/**
 * Copyright (C) 2011-2013 Aratelia Limited - Juan A. Rubio
 *
 * This file is part of Tizonia
 *
 * Tizonia is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Tizonia is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tizonia.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   mp3eprc_decls.h
 * @author Juan A. Rubio <juan.rubio@aratelia.com>
 * 
 * @brief  Tizonia OpenMAX IL - Mp3 Encoder processor class decls
 * 
 * 
 */

#ifndef MP3EPRC_DECLS_H
#define MP3EPRC_DECLS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <lame/lame.h>

#include "OMX_Core.h"

#include "mp3eprc.h"
#include "tizproc_decls.h"

#define INPUT_BUFFER_SIZE   (5*8192)
#define OUTPUT_BUFFER_SIZE  8192 /* Must be an integer multiple of 4. */

struct mp3eprc
{
  /* Object */
  const struct tizproc _;
  OMX_AUDIO_PARAM_PCMMODETYPE pcmmode_;
  OMX_AUDIO_PARAM_MP3TYPE mp3type_;
  lame_t lame_;
  size_t remaining_;
  unsigned long frame_count_;
  unsigned char in_buff_ [INPUT_BUFFER_SIZE];
  unsigned char out_buff_ [OUTPUT_BUFFER_SIZE];
  OMX_BUFFERHEADERTYPE *p_inhdr_;
  OMX_BUFFERHEADERTYPE *p_outhdr_;
  int next_synth_sample_;
  bool eos_;
};

#ifdef __cplusplus
}
#endif

#endif /* MP3EPRC_DECLS_H */
