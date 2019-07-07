/* -*- c++ -*- */
/* 
 * Copyright 2019 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_VERILOG_VERILOG_AXI_II_IMPL_H
#define INCLUDED_VERILOG_VERILOG_AXI_II_IMPL_H

#include <verilog/verilog_axi_ii.h>
#include <string>

#include "gr_verilog_iotype.h"

#define SLASH "/"

namespace gr {
  namespace verilog {

    class verilog_axi_ii_impl : public verilog_axi_ii
    {
     private:
      /* gr::verilog::verilog_axi_ii private member variables  */
      
      // The path and name of user's verilog module
      // Construct by (const char *filename)
      std::string verilog_module_path;
      std::string verilog_module_name;
      
      // The path of makefile template
      std::string makefile_template_path;

      // The path of cpp template 
      std::string cpp_template_path;

      // The class that control the shared library
      // Use verilog_module_so.load_lib(std::string verilog_module_path, std::string lib_name) to load library
      // Use verilog_module_so.find_func(std::string func_name) to get the function
      // Use verilog_module_so.release_lib(std::string string lib_name) to release the library
      Shared_lib verilog_module_so;

      // typedef void (*Simulation_func)
      typedef void (*Simulation_func) (const ITYPE &verilog_input, const OTYPE &verilog_ouput, const unsigned int &main_time);
      Simulation_func sim;


      unsigned int main_time;

      /* gr::verilog::verilog_axi_ii private member variables  */


      /* gr::verilog::verilog_axi_ii private member functions */

      /* Construct routine */
      // The function that call Verilator (Makefile) to generate the cpp code
      //int generate_verilator_file() throw(std::runtime_error);

      /*
      // Parse the Verilator generate file and extract the port map
      // The port map should be stored in Veriloag_data verilog_data
      int init_port_map() throw(std::logic_error);
      */

      // The function that call g++ (Makefile) to generate the shared library
      // There might be some modifications on the tempalte cpp interface file
      // ! generate_verilator_file will be included in the this->generate_so()
      int generate_so() throw(std::runtime_error);

      // The function that load the shared library that generated above
      // with the Shared_lib verilog_module_so
      int load_lib() throw(std::runtime_error);
      /* Construct routine */

      /* Destruct routine */

      int release_lib() throw(std::runtime_error);

      /* Destruct routine */

      /* gr::verilog::verilog_axi_ii private member functions */

     public:
      verilog_axi_ii_impl(const char *filename);
      ~verilog_axi_ii_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace verilog
} // namespace gr

#endif /* INCLUDED_VERILOG_VERILOG_AXI_II_IMPL_H */

