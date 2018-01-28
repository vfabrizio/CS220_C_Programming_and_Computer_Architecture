  #include "stats.h"

#define TLB_ACCESS_TIME       10 /* 10 ns */
#define MEM_ACCESS_TIME      100 /* 100 ns */
#define DISK_IO_TIME   	10000000 /* 10 million ns = 10 ms */

double compute_access_time() {
   /* TASK 6: Compute the average mean access time.  You should only need the
    * numbers contained in the following variables. You may or may not need to
    * use them all:
    *    pagefaults_count   - the number of page faults that occurred
    *                         (note: this _does_ include the unavoidable page
    *                                fault when a process is first brought into
    *                                memory upon starting)
    *    tlbhits_count      - the number of tlbhits that occurred
    *    writes_count       - the number of stores/writes that occurred
    *    reads_count        - the number of reads that occurred
    *
    * Any other values you might need are composites of the above values.  Some
    * of these computations have been done for you, in case you need them.
    */

    double timeForFaults = pagefaults_count * DISK_IO_TIME;
    double timeForHits = tlbhits_count * TLB_ACCESS_TIME;
    double timeForMisses = (reads_count + writes_count - tlbhits_count) * MEM_ACCESS_TIME * 2;

	return timeForFaults + timeForHits + timeForMisses;
}
