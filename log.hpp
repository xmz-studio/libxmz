/*
 * log.hpp
 * Copyright (c) 2026 XMZ Studio
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see
 * <https://www.gnu.org/licenses/lgpl-3.0.html>.
 */

#ifndef LIBXMZ_LOG_HPP
#define LIBXMZ_LOG_HPP
#include "io.hpp"
#include "time.hpp"
#include "color.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

namespace xmz {
	namespace log {
		namespace lv {
			/* log level macros */
			inline constexpr std::string_view	EMERG	= "[Emerg]:";
			inline constexpr std::string_view	ALERT	= "[Alert]:";
			inline constexpr std::string_view	CRIT	= "[Crit]:";
			inline constexpr std::string_view	ERROR	= "[Error]:";
			inline constexpr std::string_view	WARN	= "[Warn]:";
			inline constexpr std::string_view	NOTICE	= "[Notice]:";
			inline constexpr std::string_view	INFO	= "[Info]:";
			inline constexpr std::string_view	DEBUG	= "[Debug]:";
			inline constexpr std::string_view	KEEP	= "[Keep]:"; // no definition for the time being

			inline constexpr std::string_view	emerg	= xmz::color::TRBWC + EMERG + xmz::color::NC;
			inline constexpr std::string_view	alert	= xmz::color::RBYC + ALERT + xmz::color::NC;
			inline constexpr std::string_view	crit	= xmz::color::RBWC + CRIT + xmz::color::NC;
			inline constexpr std::string_view	error	= xmz::color::RED + ERROR + xmz::color::NC;
			inline constexpr std::string_view	warn	= xmz::color::YELLOW + WARN + xmz::color::NC;
			inline constexpr std::string_view	notice	= xmz::color::CYAN + NOTICE + xmz::color::NC;
			inline constexpr std::string_view	info	= xmz::color::GREEN + INFO + xmz::color::NC;
			inline constexpr std::string_view	debug	= xmz::color::GRAY + DEBUG + xmz::color::NC;
		} /* namespace lv */
		inline std::string get_time() { return "[" + xmz::get_time_str() + "]:"; }

		template<typename... Args>
		inline void emerg(const Args&... args)
		{ xmz::perrln(xmz::log::lv::emerg, get_time(), args...); }

		template<typename... Args>
		inline void alert(const Args&... args)
		{ xmz::perrln(xmz::log::lv::alert, get_time(), args...); }

		template<typename... Args>
		inline void crit(const Args&... args)
		{ xmz::perrln(xmz::log::lv::crit, get_time(), args...); }

		template<typename... Args>
		inline void error(const Args&... args)
		{ xmz::perrln(xmz::log::lv::error, get_time(), args...); }

		template<typename... Args>
		inline void warn(const Args&... args)
		{ xmz::perrln(xmz::log::lv::warn, get_time(), args...); }

		template<typename... Args>
		inline void notice(const Args&... args)
		{ xmz::perrln(xmz::log::lv::notice, get_time(), args...); }

		template<typename... Args>
		inline void info(const Args&... args)
		{ xmz::println(xmz::log::lv::info, get_time(), args...); }

		template<typename... Args>
		inline void debug(const Args&... args)
		{ xmz::perrln(xmz::log::lv::debug, get_time(), args...); }

		inline constexpr auto err = [](const std::string& msg) { error(msg); };

		template<typename... Args>
		inline void custom(const std::string& info_type, const Args&... args)
		{ xmz::println("[" + info_type + "]", args...); }
	} /* namespace log */
}
#endif /* LIBXMZ_LOG_HPP */

