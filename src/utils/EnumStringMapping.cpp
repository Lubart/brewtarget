/*
 * utils/EnumStringMapping.cpp is part of Brewtarget, and is Copyright the following
 * authors 2021-2023
 * - Matt Young <mfsy@yahoo.com>
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "utils/EnumStringMapping.h"

#include <algorithm>

EnumAndItsString::EnumAndItsString(QString string, int native) :
   string{string},
   native{native} {
   return;
}

std::optional<int> EnumStringMapping::stringToEnumAsInt(QString const & stringValue,
                                                        bool const caseInensitiveFallback) const {
   auto match = std::find_if(this->begin(),
                             this->end(),
                             [stringValue](EnumAndItsString const & ii){return stringValue == ii.string;});
   //
   // If we didn't find an exact match, we'll try a case-insensitive one if so-configured.  (We don't do this by
   // default as the assumption is that it's rare we'll need the case insensitivity.)
   //
   if (match == this->end() && caseInensitiveFallback) {
      match = std::find_if(
         this->begin(),
         this->end(),
         [stringValue](EnumAndItsString const & ii){return stringValue.toLower() == ii.string.toLower();}
      );
   }

   if (match == this->end()) {
      return std::nullopt;
   }

   return std::optional<int>{match->native};
}

std::optional<QString> EnumStringMapping::enumAsIntToString(int const enumValue) const {
   auto match = std::find_if(this->begin(),
                             this->end(),
                             [enumValue](EnumAndItsString const & ii){return enumValue == ii.native;});
   if (match == this->end()) {
      return std::nullopt;
   }

   return std::optional<QString>{match->string};
}
