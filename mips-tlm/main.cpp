/******************************************************
 * This is the main file for the mips ArchC model     *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

const char *project_name="mips";
const char *project_file="mips.ac";
const char *archc_version="2.2";
const char *archc_options="-abi ";

#include  <iostream>
#include  <systemc.h>
#include  <string.h>
#include  "ac_stats_base.H"
#include  "mips.H"

#include  "ac_tlm_mem.h"
#include  "ac_tlm_router.h"
#include  "ac_tlm_peripheral.h"

using user::ac_tlm_mem;
using user::ac_tlm_router;
using user::ac_tlm_peripheral;

int sc_main(int ac, char *av[])
{

  int ac_aux;
  char **av_aux;
  //!  ISA simulator
  mips mips_proc1("mips");
  //mips mips_proc2("mips2");
  //mips mips_proc3("mips3");
  //mips mips_proc4("mips4");
  ac_tlm_mem mem("mem", 100*1024*1024);
  ac_tlm_router router("router");
  ac_tlm_peripheral peripheral("peripheral"); 

	
  router.MEM_port(mem.target_export);
  
  router.PERIPHERAL_port(peripheral.target_export); 

  mips_proc1.DM_port(router.target_export);
  //mips_proc2.DM_port(router.target_export);
  //mips_proc3.DM_port(router.target_export);
  //mips_proc4.DM_port(router.target_export);

#ifdef AC_DEBUG
  ac_trace("mips_proc1.trace");
  ac_trace("mips_proc2.trace");
#endif 
  ac_aux = ac;
  av_aux = (char **) calloc(ac,sizeof(char *));
  
  for (int i=0;i<ac;i++)
  {
	av_aux[i] = (char *) calloc(strlen(av[i]),sizeof(char));
	strcpy(av_aux[i] ,av[i]);
  }
  
  mips_proc1.init(ac, av);
  
  /*ac = ac_aux;
  for (int i=0;i<ac;i++)
	strcpy(av[i] ,av_aux[i]);
  
  mips_proc2.init(ac, av);
  
  ac = ac_aux;
  for (int i=0;i<ac;i++)
	strcpy(av[i] ,av_aux[i]);
  
  mips_proc3.init(ac, av);
  
  ac = ac_aux;
  for (int i=0;i<ac;i++)
	strcpy(av[i] ,av_aux[i]);
  
  mips_proc4.init(ac, av);*/
  
  mips_proc1.set_instr_batch_size(1);
  //mips_proc2.set_instr_batch_size(1);
  //mips_proc3.set_instr_batch_size(1);
  //mips_proc4.set_instr_batch_size(1);
  
  cerr << endl;

  sc_start();

  mips_proc1.PrintStat();
  //mips_proc2.PrintStat();
  //mips_proc3.PrintStat();
  //mips_proc4.PrintStat();
  cerr << endl;

#ifdef AC_STATS
  ac_stats_base::print_all_stats(std::cerr);
#endif 

#ifdef AC_DEBUG
  ac_close_trace();
#endif 

  return mips_proc1.ac_exit_status;// + mips_proc2.ac_exit_status + mips_proc3.ac_exit_status + mips_proc4.ac_exit_status;
}
