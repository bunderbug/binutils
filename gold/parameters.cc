// parameters.cc -- general parameters for a link using gold

// Copyright 2006, 2007 Free Software Foundation, Inc.
// Written by Ian Lance Taylor <iant@google.com>.

// This file is part of gold.

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
// MA 02110-1301, USA.

#include "gold.h"

#include "options.h"
#include "parameters.h"

namespace gold
{

// Initialize the parameters from the options.

Parameters::Parameters(const General_options* options)
  : optimization_level_(options->optimization_level())
{
  if (options->is_shared())
    this->output_file_type_ = OUTPUT_SHARED;
  else if (options->is_relocatable())
    this->output_file_type_ = OUTPUT_OBJECT;
  else
    this->output_file_type_ = OUTPUT_EXECUTABLE;
}

// The global variable.

const Parameters* parameters;

// Initialize the global variable.

void
initialize_parameters(const General_options* options)
{
  parameters = new Parameters(options);
}

} // End namespace gold.