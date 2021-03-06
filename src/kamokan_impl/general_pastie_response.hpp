/* Copyright 2017, Michele Santullo
 * This file is part of "kamokan".
 *
 * "kamokan" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "kamokan" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "kamokan".  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "response.hpp"
#include <string>

namespace kamokan {
	class GeneralPastieResponse : public Response {
	public:
		GeneralPastieResponse (
			const Kakoune::SafePtr<SettingsBag>& parSettings,
			std::ostream* parStreamOut,
			const Kakoune::SafePtr<cgi::Env>& parCgiEnv
		);

	protected:
		bool pastie_not_found() const;
		bool token_invalid() const;

	private:
		virtual tawashi::HttpHeader on_process() override final;
		virtual void on_mustache_prepare (mstch::map& parContext) override final;
		virtual tawashi::HttpHeader on_general_pastie_process() = 0;
		virtual void on_general_mustache_prepare (std::string&& parPastie, mstch::map& parContext) = 0;
		std::string default_pastie_lang() override;

		Storage::RetrievedPastie m_pastie_info;
	};
} //namespace kamokan
