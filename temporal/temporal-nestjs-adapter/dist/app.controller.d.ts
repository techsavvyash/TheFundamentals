import { AppService } from './app.service';
import { TemporalService } from './temporal.service';
export declare class AppController {
    private readonly appService;
    private readonly temporalService;
    constructor(appService: AppService, temporalService: TemporalService);
    getHello(): Promise<any>;
}
