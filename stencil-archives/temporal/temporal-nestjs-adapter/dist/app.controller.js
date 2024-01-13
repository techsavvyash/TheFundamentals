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
exports.AppController = void 0;
const common_1 = require("@nestjs/common");
const app_service_1 = require("./app.service");
const temporal_service_1 = require("./temporal.service");
const workflow_1 = require("./temporal/workflows/workflow");
const activities = require("./temporal/activities");
let AppController = class AppController {
    constructor(appService, temporalService) {
        this.appService = appService;
        this.temporalService = temporalService;
        this.temporalService = new temporal_service_1.TemporalService('localhost:7233', './temporal/workflows', activities);
    }
    async getHello() {
        try {
            const result = await this.temporalService
                .run(workflow_1.exampleWorkflow, 'default', ['Temporal'], 'random-id-for-test')
                .catch((err) => {
                console.error(err);
                process.exit(1);
            });
            return result;
        }
        catch (err) {
            console.error(err);
        }
    }
};
exports.AppController = AppController;
__decorate([
    (0, common_1.Get)(),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", Promise)
], AppController.prototype, "getHello", null);
exports.AppController = AppController = __decorate([
    (0, common_1.Controller)(),
    __metadata("design:paramtypes", [app_service_1.AppService,
        temporal_service_1.TemporalService])
], AppController);
//# sourceMappingURL=app.controller.js.map