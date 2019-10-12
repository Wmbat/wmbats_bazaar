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
       * @brief An enum to express the severity
       * of a message.
       */
      enum class severity_level : size_t
      {
         e_info        = 0,
         e_warning     = 1,
         e_critical    = 2,
         e_error       = 3
      };

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

      template<severity_level level>
      inline void log( std::string const& msg )
      {
         if constexpr ( level == severity_level::e_info )
         {
            if ( show_info )
            {
               log_->info( msg );
            }
         }
         
         if constexpr ( level == severity_level::e_warning )
         {
            if ( show_warnings )
            {
               log_->warn( msg );
            }
         }

         if constexpr ( level == severity_level::e_critical )
         {
            if ( show_critical )
            {
               log_->critical( msg );
            }
         }

         if constexpr ( level == severity_level::e_error )
         {
            if ( show_errors )
            {
               log_->error( msg );
            }
         }
      }

      template<severity_level level, typename... arguments>
      inline void log( std::string_view msg, arguments const& ...args )
      {
         if constexpr ( level == severity_level::e_info )
         {
            if ( show_info )
            {
               log_->info( msg, args... );
            }
         }
         
         if constexpr ( level == severity_level::e_warning )
         {
            if ( show_warnings )
            {
               log_->warn( msg, args... );
            }
         }

         if constexpr ( level == severity_level::e_critical )
         {
            if ( show_critical )
            {
               log_->critical( msg, args... );
            }
         }

         if constexpr ( level == severity_level::e_error )
         {
            if ( show_errors )
            {
               log_->error( msg, args... );
            }
         }
      }

      [[deprecated]]
      inline static void init( const char* logger_name, const char* display_pattern )
      {
         logger_ = spdlog::stdout_color_mt( logger_name );
         logger_->set_pattern( display_pattern );
      }

      [[deprecated]]
      inline static spdlog::logger& get_logger( )
      {
         return *logger_;
      }

   private:
      std::shared_ptr<spdlog::logger> log_;
     
      bool show_info;
      bool show_warnings;
      bool show_critical;
      bool show_errors;

      [[deprecated]]
      inline static std::shared_ptr<spdlog::logger> logger_;
   };
}

#endif // BAZAAR_LOGGER_HPP
