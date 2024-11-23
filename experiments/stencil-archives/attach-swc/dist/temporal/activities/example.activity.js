"use strict";
Object.defineProperty(exports, "__esModule", {
    value: true
});
Object.defineProperty(exports, "exampleActivity", {
    enumerable: true,
    get: function() {
        return exampleActivity;
    }
});
async function exampleActivity(name) {
    // Implement the activity logic here
    return await `Hello, ${name}!`;
}
