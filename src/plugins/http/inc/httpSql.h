/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TDENGINE_HTTP_SQL_H
#define TDENGINE_HTTP_SQL_H


int32_t httpAddToSqlCmdBuffer(HttpContext *pContext, const char *const format, ...);
int32_t httpAddToSqlCmdBufferNoTerminal(HttpContext *pContext, const char *const format, ...);
int32_t httpAddToSqlCmdBufferWithSize(HttpContext *pContext, int mallocSize);
int32_t httpAddToSqlCmdBufferTerminal(HttpContext *pContext);

bool httpMallocMultiCmds(HttpContext *pContext, int cmdSize, int bufferSize);
bool httpReMallocMultiCmdsSize(HttpContext *pContext, int cmdSize);
bool httpReMallocMultiCmdsBuffer(HttpContext *pContext, int bufferSize);
void httpFreeMultiCmds(HttpContext *pContext);

HttpSqlCmd *httpNewSqlCmd(HttpContext *pContext);
HttpSqlCmd *httpCurrSqlCmd(HttpContext *pContext);
int httpCurSqlCmdPos(HttpContext *pContext);

void httpTrimTableName(char *name);
int httpShrinkTableName(HttpContext *pContext, int pos, char *name);
char *httpGetCmdsString(HttpContext *pContext, int pos);

#endif
