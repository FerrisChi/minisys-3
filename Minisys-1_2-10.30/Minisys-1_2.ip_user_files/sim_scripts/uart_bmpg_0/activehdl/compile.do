vlib work
vlib activehdl

vlib activehdl/xil_defaultlib

vmap xil_defaultlib activehdl/xil_defaultlib

vlog -work xil_defaultlib  -v2k5 \
"../../../../Minisys-1_2.gen/sources_1/ip/uart_bmpg_0/uart_bmpg.v" \
"../../../../Minisys-1_2.gen/sources_1/ip/uart_bmpg_0/upg.v" \
"../../../../Minisys-1_2.gen/sources_1/ip/uart_bmpg_0/sim/uart_bmpg_0.v" \


vlog -work xil_defaultlib \
"glbl.v"

