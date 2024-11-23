import { Controller, Get } from '@nestjs/common';
import { AppService } from './app.service';
import { TemporalService } from './temporal.service';
import { exampleWorkflow } from './temporal/workflows/workflow';
import * as activities from './temporal/activities';
@Controller()
export class AppController {
  constructor(
    private readonly appService: AppService,
    private readonly temporalService: TemporalService,
  ) {
    this.temporalService = new TemporalService(
      'localhost:7233',
      './temporal/workflows',
      activities,
    );
  }

  @Get()
  async getHello() {
    try {
      const result = await this.temporalService
        .run(exampleWorkflow, 'default', ['Temporal'], 'random-id-for-test')
        .catch((err) => {
          console.error(err);
          process.exit(1);
        });

      return result;
    } catch (err) {
      console.error(err);
    }
  }
}
