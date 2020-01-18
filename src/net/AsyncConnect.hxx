/* ncmpc (Ncurses MPD Client)
   (c) 2004-2020 The Music Player Daemon Project
   Project homepage: http://musicpd.org

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef NET_ASYNC_CONNECT_HXX
#define NET_ASYNC_CONNECT_HXX

#include "AsioServiceFwd.hxx"

#include <boost/asio/ip/tcp.hpp>

class AsyncConnectHandler;

class AsyncConnect {
	AsyncConnectHandler &handler;

	boost::asio::ip::tcp::socket socket;

public:
	AsyncConnect(boost::asio::io_service &io_service,
		     AsyncConnectHandler &_handler) noexcept
		:handler(_handler),
		 socket(io_service) {}

	/**
	 * Create a socket and connect it to the given address.
	 */
	void Start(const boost::asio::ip::tcp::endpoint &endpoint) noexcept;

private:
	void OnConnected(const boost::system::error_code &error) noexcept;
};

#endif
