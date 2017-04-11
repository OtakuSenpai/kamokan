/* Copyright 2017, Michele Santullo
 * This file is part of "tawashi".
 *
 * "tawashi" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "tawashi" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "tawashi".  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cgi_env.hpp"
#include <string>
#include <iostream>
#include <boost/utility/string_ref.hpp>

namespace tawashi {
	class Response {
	public:
		virtual ~Response() noexcept;

		void send();

	protected:
		enum Types {
			ContentType,
			Location
		};

		Response (Types parRespType, std::string&& parValue, const boost::string_ref& parBaseURI);
		const cgi::Env& cgi_env() const;
		void change_type (Types parRespType, std::string&& parValue);
		const boost::string_ref& base_uri() const;

	private:
		virtual void on_process();
		virtual void on_send (std::ostream& parStream) = 0;

		cgi::Env m_cgi_env;
		std::string m_resp_value;
		boost::string_ref m_base_uri;
		Types m_resp_type;
		bool m_header_sent;
	};
} //namespace tawashi
