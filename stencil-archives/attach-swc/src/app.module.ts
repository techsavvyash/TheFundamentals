import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { PrismaService } from './prisma/prisma.service';
import { user } from '@techsavvyash/user-service';
import { MonitoringModule } from '@samagra-x/stencil';
import { PrometheusController } from '@samagra-x/stencil';
import { TemporalModule } from 'nestjs-temporal';
import { TemporalWorkflowService } from '@samagra-x/stencil';
import { FileUploadModule } from '@samagra-x/stencil';
import * as activities from './temporal/activities';

@Module({
  imports: [user.UserModule, MonitoringModule, 
    TemporalModule.registerWorker({
      workerOptions: {
        namespace: 'default',
        taskQueue: 'default',
        workflowsPath: require.resolve('./temporal/workflows/example.workflow'),
        activities: {
          activities,
        },
      },
    }),
    TemporalModule.registerClient(),
    FileUploadModule,
  ],
  controllers: [AppController, PrometheusController],
  providers: [AppService, PrismaService, TemporalWorkflowService],
})
export class AppModule {}
