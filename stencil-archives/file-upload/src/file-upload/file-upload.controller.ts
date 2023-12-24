import { FileUploadService } from './file-upload.service';
import {
  Controller,
  Post,
  UploadedFile,
  UseInterceptors,
  Param,
  Get,
  Res,
  Query,
  // Req,
} from '@nestjs/common';
import { FastifyFileInterceptor } from './file-upload.interceptor';
import { MultipartFile } from './file-upload.interface';
// import { Response } from 'express';
import { FastifyReply } from 'fastify';
// import * as fastify from 'fastify';

@Controller('files')
export class FileUploadController {
  constructor(private readonly filesService: FileUploadService) {}

  // @Post('upload')
  // async handleUpload(
  //   @Req() req: fastify.FastifyRequest,
  //   @Res() res: fastify.FastifyReply<any>,
  // ) {
  //   return await this.filesService.handleUpload(req, res);
  // }

  @Post('upload-file')
  @UseInterceptors(FastifyFileInterceptor('file', {}))
  async uploadFile(
    @UploadedFile() file: MultipartFile,
    @Query('destination') destination: string, // Use @Query to retrieve the destination from the query parameters
    @Query('filename') filename: string,
  ): Promise<{
    statusCode?: number;
    message: string;
    file?: { url: string } | undefined;
  }> {
    try {
      const directory = await this.filesService.upload(
        file,
        destination,
        filename,
      );
      return {
        message: 'File uploaded successfully',
        file: { url: directory },
      };
    } catch (error) {
      console.error(`Error uploading file: ${error.message}`);
      return {
        statusCode: 500,
        message: 'File upload failed',
        file: undefined,
      };
    }
  }

  @Get('download/:destination')
  async downloadFile(
    @Param('destination') destination: string,
    @Res() res: FastifyReply,
  ): Promise<void> {
    try {
      const fileStream = await this.filesService.download(destination);
      res.headers({
        'Content-Type': 'application/octet-stream',
        'Content-Disposition': `attachment; filename=${destination}`,
      });
      fileStream.pipe(res.raw);
    } catch (error) {
      console.log('error: ', error);
      console.error(`Error downloading file: ${error.message}`);
      res.status(500).send('File download failed');
    }
  }
}
