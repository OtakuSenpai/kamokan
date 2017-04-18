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

#include "response.hpp"
#include <string>
#include <boost/utility/string_ref.hpp>

namespace tawashi {
	class PastieResponse : public Response {
	public:
		explicit PastieResponse (const IniFile& parIni);

	private:
		virtual void on_process() override;
		virtual void on_send (std::ostream& parStream) override;

		std::string m_lang_file;
		bool m_plain_text;
	};
} //namespace tawashi