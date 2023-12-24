import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { TemporalService } from './temporal.service';

@Module({
  imports: [String, Object],
  controllers: [AppController],
  providers: [AppService, String, Object, TemporalService],
})
export class AppModule {}
