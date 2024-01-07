export declare class TemporalService {
    private connection;
    private workerConnection;
    private client;
    private logger;
    private worker;
    private serverURL;
    private workflowPath;
    private activities;
    constructor(serverURL: string, workflowPath: string, activities: any);
    private createConnection;
    setupWorker(taskQueue: any): Promise<void>;
    run(workflow: any, taskQueue: string, args?: any, worflowId?: string): Promise<any>;
}
