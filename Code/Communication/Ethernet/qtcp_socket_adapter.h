/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Tue Mar 18 23:30:39 CDT 2014

    \brief This file become from: TODO

    \attention <h1><center>&copy; COPYRIGHT
    Apache License, Version 2.0, January 2004</center></h1>

    \copyright

    <h3>This file is part of <a href="http://www.TODO:.com"><strong>TODO:</strong></a> program, a TODO:.</h3>
    Copyright [2014] [Alvaro Denis Acosta Quesada]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#ifndef COMMUNICATION_ETHERNET_QTCP_SOCKET_ADAPTER_H
#define COMMUNICATION_ETHERNET_QTCP_SOCKET_ADAPTER_H

#include "Communication/comm_adapter_interface.h"

namespace COMMUNICATION {
class QTcpSocketAdapter : public CommAdapterInterface
{
  public:
    QTcpSocketAdapter() = default;
    ~QTcpSocketAdapter() = default;

    QTcpSocketAdapter(const QTcpSocketAdapter&) = delete;
    QTcpSocketAdapter& operator=(const QTcpSocketAdapter&) = delete;

    QTcpSocketAdapter(const QTcpSocketAdapter&&) = delete;
    QTcpSocketAdapter& operator=(const QTcpSocketAdapter&&) = delete;

    virtual CommErrorCode connect(int timeout) override;
    virtual CommErrorCode disconnect(int timeout) override;
    virtual CommErrorCode read(int timeout, char *data, int *n_bytes) override;
    virtual CommErrorCode write(int timeout, const char *data, int *n_bytes) override;
};
}  //namespace COMMUNICATION
#endif // COMMUNICATION_ETHERNET_QTCP_SOCKET_ADAPTER_H
