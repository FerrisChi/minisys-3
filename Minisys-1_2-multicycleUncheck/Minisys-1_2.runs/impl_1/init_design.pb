
>
Refreshing IP repositories
234*coregenZ19-234h px? 
?
 Loaded user IP repository '%s'.
1135*coregen2q
]v:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/SEU_CSE_507_user_uart_bmpg_1.32default:defaultZ19-1700h px? 
|
"Loaded Vivado IP repository '%s'.
1332*coregen23
C:/Xilinx/Vivado/2021.1/data/ip2default:defaultZ19-2313h px? 
t
Command: %s
53*	vivadotcl2C
/link_design -top minisys -part xc7a100tfgg484-12default:defaultZ4-113h px? 
g
#Design is defaulting to srcset: %s
437*	planAhead2
	sources_12default:defaultZ12-437h px? 
j
&Design is defaulting to constrset: %s
434*	planAhead2
	constrs_12default:defaultZ12-434h px? 
W
Loading part %s157*device2$
xc7a100tfgg484-12default:defaultZ21-403h px? 
?
-Reading design checkpoint '%s' for cell '%s'
275*project2y
eV:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.runs/impl_1/.Xil/Vivado-7876-FCXiaoXin/cpuclk/cpuclk.dcp2default:default2
cpuclk2default:defaultZ1-454h px? 
?
-Reading design checkpoint '%s' for cell '%s'
275*project2m
Yv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.gen/sources_1/ip/uart_bmpg_0/uart_bmpg_0.dcp2default:default2
uartpg2default:defaultZ1-454h px? 
?
-Reading design checkpoint '%s' for cell '%s'
275*project2y
eV:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.runs/impl_1/.Xil/Vivado-7876-FCXiaoXin/prgrom/prgrom.dcp2default:default2
ROM/instmem2default:defaultZ1-454h px? 
?
-Reading design checkpoint '%s' for cell '%s'
275*project2s
_V:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.runs/impl_1/.Xil/Vivado-7876-FCXiaoXin/ram/ram.dcp2default:default2

memory/ram2default:defaultZ1-454h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0492default:default2
1135.5392default:default2
0.0002default:defaultZ17-268h px? 
g
-Analyzing %s Unisim elements for replacement
17*netlist2
3912default:defaultZ29-17h px? 
j
2Unisim Transformation completed in %s CPU seconds
28*netlist2
02default:defaultZ29-28h px? 
x
Netlist was created with %s %s291*project2
Vivado2default:default2
2021.12default:defaultZ1-479h px? 
K
)Preparing netlist for logic optimization
349*projectZ1-570h px? 
?
LRemoving redundant IBUF, %s, from the path connected to top-level port: %s 
35*opt2,
cpuclk/inst/clkin1_ibufg2default:default2
fpga_clk2default:defaultZ31-35h px? 
?
NRemoving redundant IBUF since it is not being driven by a top-level port. %s 
32*opt2<
(uartpg/inst/upg_inst/upg_clk_i_IBUF_inst2default:defaultZ31-32h px? 
?
NRemoving redundant IBUF since it is not being driven by a top-level port. %s 
32*opt2<
(uartpg/inst/upg_inst/upg_rst_i_IBUF_inst2default:defaultZ31-32h px? 
?
LRemoving redundant IBUF, %s, from the path connected to top-level port: %s 
35*opt2;
'uartpg/inst/upg_inst/upg_rx_i_IBUF_inst2default:default2
rx2default:defaultZ31-35h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[0]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_adr_o_OBUF[10]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_adr_o_OBUF[11]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_adr_o_OBUF[12]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_adr_o_OBUF[13]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_adr_o_OBUF[14]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[1]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[2]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[3]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[4]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[5]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[6]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[7]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[8]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_adr_o_OBUF[9]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2<
(uartpg/inst/upg_inst/upg_clk_o_OBUF_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[0]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[10]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[11]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[12]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[13]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[14]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[15]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[16]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[17]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[18]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[19]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[1]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[20]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[21]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[22]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[23]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[24]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[25]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[26]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[27]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[28]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[29]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[2]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[30]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2@
,uartpg/inst/upg_inst/upg_dat_o_OBUF[31]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[3]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[4]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[5]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[6]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[7]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[8]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2?
+uartpg/inst/upg_inst/upg_dat_o_OBUF[9]_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2=
)uartpg/inst/upg_inst/upg_done_o_OBUF_inst2default:defaultZ31-33h px? 
?
FRemoving redundant OBUF since it is not driving a top-level port. %s 
33*opt2<
(uartpg/inst/upg_inst/upg_wen_o_OBUF_inst2default:defaultZ31-33h px? 
?
?Could not create '%s' constraint because net '%s' is not directly connected to top level port. Synthesis is ignored for %s but preserved for implementation.
528*constraints2 
IBUF_LOW_PWR2default:default2$
cpuclk/clk_in12default:default2 
IBUF_LOW_PWR2default:default8Z18-550h px? 
?
$Parsing XDC File [%s] for cell '%s'
848*designutils2l
Vv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk_board.xdc2default:default2!
cpuclk/inst	2default:default8Z20-848h px? 
?
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2l
Vv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk_board.xdc2default:default2!
cpuclk/inst	2default:default8Z20-847h px? 
?
$Parsing XDC File [%s] for cell '%s'
848*designutils2f
Pv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc2default:default2!
cpuclk/inst	2default:default8Z20-848h px? 
?
%Done setting XDC timing constraints.
35*timing2f
Pv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc2default:default2
572default:default8@Z38-35h px? 
?
Deriving generated clocks
2*timing2f
Pv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc2default:default2
572default:default8@Z38-2h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2 
get_clocks: 2default:default2
00:00:082default:default2
00:00:092default:default2
1421.5352default:default2
285.9962default:defaultZ17-268h px? 
?
-Finished Parsing XDC File [%s] for cell '%s'
847*designutils2f
Pv:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/sources_1/ip/cpuclk/cpuclk.xdc2default:default2!
cpuclk/inst	2default:default8Z20-847h px? 
?
Parsing XDC File [%s]
179*designutils2i
SV:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/constrs_1/imports/xdc/minisys.xdc2default:default8Z20-179h px? 
?
Finished Parsing XDC File [%s]
178*designutils2i
SV:/cpu/Minisys-1_2-multicycleUnc/Minisys-1_2.srcs/constrs_1/imports/xdc/minisys.xdc2default:default8Z20-178h px? 
u
)Pushed %s inverter(s) to %s load pin(s).
98*opt2
02default:default2
02default:defaultZ31-138h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2 
00:00:00.0022default:default2
1421.5352default:default2
0.0002default:defaultZ17-268h px? 
~
!Unisim Transformation Summary:
%s111*project29
%No Unisim elements were transformed.
2default:defaultZ1-111h px? 
?
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
162default:default2
552default:default2
02default:default2
02default:defaultZ4-41h px? 
]
%s completed successfully
29*	vivadotcl2
link_design2default:defaultZ4-42h px? 
?
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2!
link_design: 2default:default2
00:00:152default:default2
00:00:162default:default2
1421.5352default:default2
285.9962default:defaultZ17-268h px? 


End Record