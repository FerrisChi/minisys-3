set_property SRC_FILE_INFO {cfile:v:/cpu/Minisys-1_2/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc rfile:../Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc id:1 order:EARLY scoped_inst:cpuclk/inst} [current_design]
set_property SRC_FILE_INFO {cfile:V:/cpu/Minisys-1_2/Minisys-1_2.srcs/constrs_1/imports/xdc/minisys.xdc rfile:../Minisys-1_2.srcs/constrs_1/imports/xdc/minisys.xdc id:2} [current_design]
current_instance cpuclk/inst
set_property src_info {type:SCOPED_XDC file:1 line:57 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk_in1]] 0.100
current_instance
set_property src_info {type:XDC file:2 line:4 export:INPUT save:INPUT read:READ} [current_design]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets start_pg_IBUF]
set_property src_info {type:XDC file:2 line:7 export:INPUT save:INPUT read:READ} [current_design]
set_property -dict {IOSTANDARD LVCMOS33 PACKAGE_PIN Y19} [get_ports rx]
