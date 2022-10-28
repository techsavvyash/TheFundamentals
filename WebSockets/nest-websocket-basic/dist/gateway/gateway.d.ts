import { Server } from 'socket.io';
import { OnModuleInit } from "@nestjs/common";
export declare class MyGateway implements OnModuleInit {
    server: Server;
    onModuleInit(): any;
    onNewMessage(body: any): void;
}
