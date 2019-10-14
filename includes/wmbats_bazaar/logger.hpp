/*!
 * @author wmbat@protonmail.com
 *
 * Copyright (C) 2019 Wmbat
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * You should have received a copy of the GNU General Public License
 * GNU General Public License for more details.
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BAZAAR_LOGGER_HPP
#define BAZAAR_LOGGER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace bzr
{
   class logger
   {
   public:
      /**
       * @brief Default Constructor.
       */
      logger( ) = default;
      
      /**
       * @brief Constructor.
       *
       * @param name The name of the logger.
       * @param pattern The pattern the logger 
       * should use to display information.
       */
      inline logger( std::string const& name, std::string const& pattern )
      {
         log_ = spdlog::stdout_color_mt( name );
         log_->set_pattern( pattern );

         show_info = true;
         show_warnings = true;
         show_critical = true;
         show_errors = true;
      }

      /**
       * @brief Log informational messages.
       *
       * @param msg The message to log.
       */
      inline void log_info( std::string const& msg )
      {
         if ( show_info )
         {
            log_->info( msg );
         }
      }

      inline void log_warning( std::string const& msg )
      {
         if ( show_warnings )
         {
            log_->warn( msg );
         }
      }

      inline void log_error( std::string const& msg )
      {
         if ( show_errors )
         {
            log_->error( msg );
         }
      }

      template<typename... arguments>
      inline void log_info( char const* msg, arguments const& ...args )
      {
         if ( show_info )
         {
            log_->info( msg, args... );
         }
      }

      template<typename... arguments>
      inline void log_warning( char const* msg, arguments const& ...args )
      {
         if ( show_warnings )
         {
            log_->warn( msg, args... );
         }
      }

      template<typename... arguments>
      inline void log_error( char const* msg, arguments const& ...args )
      {
         if ( show_errors )
         {
            log_->error( msg, args... );
         }
      }

   private:
      std::shared_ptr<spdlog::logger> log_;
     
      bool show_info;
      bool show_warnings;
      bool show_critical;
      bool show_errors;
   };
}

#endif // BAZAAR_LOGGER_HPP
