"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.TemporalService = void 0;
const common_1 = require("@nestjs/common");
const client_1 = require("@temporalio/client");
const worker_1 = require("@temporalio/worker");
const crypto_1 = require("crypto");
let TemporalService = class TemporalService {
    constructor(serverURL, workflowPath, activities) {
        this.serverURL = 'localhost:7233';
        this.workflowPath = './temporal/workflows';
        this.serverURL = serverURL;
        this.logger = new common_1.Logger('TemporalService');
        this.connection = null;
        this.workerConnection = null;
        this.client = null;
        this.worker = null;
        this.workflowPath = workflowPath;
        this.activities = activities;
    }
    async createConnection() {
        if (this.connection === null) {
            try {
                this.connection = await client_1.Connection.connect({ address: this.serverURL });
                this.logger.log('Connected to temporal server at ', this.serverURL, '🚀');
            }
            catch (err) {
                this.logger.error('Error while connecting to temporal server: ', err);
            }
        }
    }
    async setupWorker(taskQueue) {
        if (this.workerConnection === null) {
            this.workerConnection = await worker_1.NativeConnection.connect({
                address: this.serverURL,
            });
        }
        this.worker = await worker_1.Worker.create({
            connection: this.workerConnection,
            namespace: 'default',
            taskQueue,
            workflowsPath: require.resolve(this.workflowPath),
            activities: this.activities,
        });
        await this.worker.run();
    }
    async run(workflow, taskQueue, args, worflowId) {
        try {
            await this.setupWorker(taskQueue);
        }
        catch (err) {
            this.logger.error('Error while setting up worker: ', err);
        }
        await this.createConnection();
        this.client = new client_1.Client({
            connection: this.connection,
        });
        const handle = await this.client.worflow.start(workflow, {
            taskQueue,
            args: args || ['Temporal'],
            workflowId: worflowId || 'workflow-' + (0, crypto_1.randomUUID)(),
        });
        return await handle.result();
    }
};
exports.TemporalService = TemporalService;
exports.TemporalService = TemporalService = __decorate([
    (0, common_1.Injectable)(),
    __metadata("design:paramtypes", [String, String, Object])
], TemporalService);
//# sourceMappingURL=temporal.service.js.map