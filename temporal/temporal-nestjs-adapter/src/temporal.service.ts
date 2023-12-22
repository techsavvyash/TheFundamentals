import { Injectable, Logger } from '@nestjs/common';
import { Connection, Client } from '@temporalio/client';
import { NativeConnection, Worker } from '@temporalio/worker';
import { randomUUID } from 'crypto';

@Injectable()
export class TemporalService {
  private connection: any;
  private workerConnection: any;
  private client: any;
  private logger: Logger;
  private worker: any;
  private serverURL: string = 'localhost:7233';
  private workflowPath: string = './temporal/workflows';
  private activities: any;

  constructor(serverURL: string, workflowPath: string, activities: any) {
    this.serverURL = serverURL;
    this.logger = new Logger('TemporalService');
    this.connection = null;
    this.workerConnection = null;
    this.client = null;
    this.worker = null;
    this.workflowPath = workflowPath;
    this.activities = activities;
  }

  private async createConnection() {
    // this function makes sure we don't create connections on each invocation of run on an instance
    if (this.connection === null) {
      try {
        this.connection = await Connection.connect({ address: this.serverURL });
        this.logger.log(
          'Connected to temporal server at ',
          this.serverURL,
          '🚀',
        );
      } catch (err) {
        this.logger.error('Error while connecting to temporal server: ', err);
      }
    }
  }

  public async setupWorker(taskQueue) {
    if (this.workerConnection === null) {
      this.workerConnection = await NativeConnection.connect({
        address: this.serverURL,
      });
    }

    this.worker = await Worker.create({
      connection: this.workerConnection,
      namespace: 'default',
      taskQueue,
      workflowsPath: require.resolve(this.workflowPath),
      activities: this.activities,
    });

    await this.worker.run();
  }

  public async run(
    workflow: any,
    taskQueue: string,
    args?: any,
    worflowId?: string,
  ) {
    try {
      await this.setupWorker(taskQueue);
    } catch (err) {
      this.logger.error('Error while setting up worker: ', err);
    }
    // this.connection = await Connection.connect({ address: this.serverURL });
    await this.createConnection();
    this.client = new Client({
      connection: this.connection,
    });

    const handle = await this.client.worflow.start(workflow, {
      taskQueue,
      // type inference works! args: [name: string]
      args: args || ['Temporal'],
      // in practice, use a meaningful business ID, like customerId or transactionId
      workflowId: worflowId || 'workflow-' + randomUUID(),
    });

    return await handle.result();
  }
}
