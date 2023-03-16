/*
 * @Author: sjchanson 13560469332@163.com
 * @Date: 2022-05-18 11:48:53
 * @LastEditors: sjchanson 13560469332@163.com
 * @LastEditTime: 2022-06-07 12:37:30
 * @FilePath: /iEDA/src/iSTA/include/Config.hh
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file Config.hh
 * @author simin tao (taosm@pcl.ac.cn)
 * @brief
 * @version 0.1
 * @date 2021-07-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once

#ifdef ZLIB_FOUND

#include <zlib.h>

#else  // ZLIB_FOUND

#include <stdio.h>

#define gzFile FILE
#define gzopen fopen
#define gzclose fclose
#define gzgets(stream, s, size) fgets(s, size, stream)
#define gzprintf fprintf
#define Z_NULL nullptr

constexpr unsigned c_vertex_slew_data_bucket_size = 1;
constexpr unsigned c_vertex_path_delay_data_bucket_size = 1;

#include "HashMap.hh"
#include "HashSet.hh"
#include "Map.hh"
#include "Set.hh"
#include "Vector.hh"
#include "log/Log.hh"
#include "string/Str.hh"
#include "string/StrMap.hh"
#include "tcl/ScriptEngine.hh"
#include "time/Time.hh"
#include "usage/usage.hh"

namespace iSTA_Proto { namespace Common {

using ieda::HashMap;
using ieda::HashSet;
using ieda::Log;
using ieda::Map;
using ieda::Multimap;
using ieda::Set;
using ieda::Str;
using ieda::StrMap;
using ieda::Time;
using ieda::Vector;

}  // namespace iSTA_proto_server

}
#endif