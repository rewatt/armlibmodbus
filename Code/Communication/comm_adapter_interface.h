/*! \file TODO:
    \author Alvaro Denis Acosta Quesada <denisacostaq@gmail.com>
    \date Tue Mar 18 23:18:44 CDT 2014

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

#ifndef COMMUNICATION_COMM_ADAPTER_INTERFACE_H
#define COMMUNICATION_COMM_ADAPTER_INTERFACE_H

#include "Communication/comm_error_code.h"

namespace COMMUNICATION
{
  /*! \brief CommInterface is a common interface for \"all\" transport protocols
   * \brief The CommInterface class use a facade pattern.
   */


  /*! \brief CommAdapterInterface is a common adaptor interface for \"all\" transport
   * \brief protocols, if you need use a diferent transport layer, inherit from this
   * \brief your own adaptor such as QTcpSocketAdapter do it.
 * \brief The CommAdapterInterface class
 */
class CommAdapterInterface
{
  public:
    CommAdapterInterface() = default;
    virtual ~CommAdapterInterface() = default;

    CommAdapterInterface(const CommAdapterInterface&) = delete;
    CommAdapterInterface& operator=(const CommAdapterInterface&) = delete;

    CommAdapterInterface(const CommAdapterInterface&&) = delete;
    CommAdapterInterface& operator=(const CommAdapterInterface&&) = delete;

    virtual CommErrorCode connect(int timeout) = 0;
    virtual CommErrorCode disconnect(int timeout) = 0;
    virtual CommErrorCode read(int timeout, char *data, int *n_bytes) = 0;
    virtual CommErrorCode write(int timeout, const char *data, int *n_bytes) = 0;
};
}  //namespace COMMUNICATION
#endif // COMMUNICATION_COMM_ADAPTER_INTERFACE_H
