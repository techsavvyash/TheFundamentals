"use strict";
Object.defineProperty(exports, "__esModule", {
    value: true
});
Object.defineProperty(exports, "exampleWorkflow", {
    enumerable: true,
    get: function() {
        return exampleWorkflow;
    }
});
const _workflow = require("@temporalio/workflow");
const activities = (0, _workflow.proxyActivities)({
    startToCloseTimeout: '1 minute'
});
async function exampleWorkflow(name) {
    await (0, _workflow.sleep)(100000);
    return await activities.exampleActivity(name);
}
