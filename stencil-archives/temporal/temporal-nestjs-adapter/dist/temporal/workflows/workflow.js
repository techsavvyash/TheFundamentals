"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.exampleWorkflow = void 0;
const workflow_1 = require("@temporalio/workflow");
const activities = (0, workflow_1.proxyActivities)({
    startToCloseTimeout: '1 minute',
});
async function exampleWorkflow(name) {
    await (0, workflow_1.sleep)(1000);
    return await activities.exampleActivity(name);
}
exports.exampleWorkflow = exampleWorkflow;
//# sourceMappingURL=workflow.js.map