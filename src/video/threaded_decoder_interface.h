/*!
 *  Copyright (c) 2019 by Contributors if not otherwise specified
 * \file video_decoder_interface.h
 * \brief Video Decoder Interface
 */

#ifndef DECORD_VIDEO_THREADED_DECODER_INTERFACE_H_
#define DECORD_VIDEO_THREADED_DECODER_INTERFACE_H_

#include "ffmpeg/ffmpeg_common.h"

namespace decord {
class ThreadedDecoderInterface {
    public:
        virtual void SetCodecContext(AVCodecContext *dec_ctx, int width = -1, int height = -1) = 0;
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual void Clear() = 0;
        virtual void Push(ffmpeg::AVPacketPtr pkt) = 0;
        virtual void Push(ffmpeg::AVPacketPtr pkt, DLTensor buf) = 0;
        virtual bool Pop(DLTensor *frame) = 0;
        virtual bool Pop(ffmpeg::AVFramePtr *frame) = 0;
        ~ThreadedDecoderInterface() = default;
};  // class ThreadedDecoderInterface

}  // namespace decord
#endif  // DECORD_VIDEO_THREADED_DECODER_INTERFACE_H_