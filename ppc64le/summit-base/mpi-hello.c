#include <ctype.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define FLAG_ON 1
#define FLAG_OFF 0

#define EARLY_EXIT -1
#define BAD_FLAG 1

typedef struct pinfo_t
{ 
  MPI_Comm comm;
  MPI_Comm comm_local;
  int size;
  int rank;
  int localsize;
  int localrank;
} pinfo_t;

typedef struct opts_t
{ 
  int messy;
  int one_rank;
} opts_t;



static inline int process_flags(pinfo_t p, int argc, char **argv, opts_t *opts)
{
  char c;
  opts->messy = FLAG_OFF;
  opts->one_rank = FLAG_OFF;
  
  while ((c = getopt(argc, argv, "moh")) != -1)
  {
    if (c == 'm')
      opts->messy = FLAG_ON;
    else if (c == 'o')
      opts->one_rank = FLAG_ON;
    else if (c == 'h')
    {
      if (p.rank == 0)
      {
        printf("Usage\n");
        printf("  mpirun -np $NRANKS ./mpi-hello\n");
        printf("Options:\n");
        printf("  -m\tmessy printing (no barrier)\n");
        printf("  -o\tonly print one rank per node\n");
        printf("  -h\tthis help message\n");
      }
      
      return EARLY_EXIT;
    }
    else if (c == '?')
      return BAD_FLAG;
  }
  
  return 0;
}



static inline void hello(pinfo_t p, opts_t opts)
{
  #define HELLO printf("Hello from rank %d/%d global %d/%d local\n", p.rank, p.size, p.localrank, p.localsize)
  
  if (opts.one_rank == FLAG_OFF)
  {
    if (opts.messy == FLAG_OFF)
    {
      for (int i=0; i<p.size; i++)
      {
        if (i == p.rank)
          HELLO;
        
        MPI_Barrier(p.comm);
      }
    }
    else if (opts.messy == FLAG_ON)
      HELLO;
  }
  else if (opts.one_rank == FLAG_ON)
  {
    if (opts.messy == FLAG_OFF)
    {
      for (int i=0; i<p.size; i+=p.localsize)
      {
        if (p.rank == i && p.localrank == 0)
          HELLO;
        
        MPI_Barrier(p.comm);
      }
    }
    else if (opts.messy == FLAG_ON)
    {
      if (p.localrank == 0)
        HELLO;
    }
  }
  
  #undef HELLO
}



int main(int argc, char **argv)
{
  pinfo_t p;
  opts_t opts;
  p.comm = MPI_COMM_WORLD;
  
  MPI_Init(NULL, NULL);
  
  MPI_Comm_size(p.comm, &p.size);
  MPI_Comm_rank(p.comm, &p.rank);
  MPI_Comm_split_type(p.comm, MPI_COMM_TYPE_SHARED, 0, MPI_INFO_NULL, &p.comm_local);
  MPI_Comm_rank(p.comm_local, &p.localrank);
  MPI_Comm_size(p.comm_local, &p.localsize);
  
  int check = process_flags(p, argc, argv, &opts);
  
  if (check != EARLY_EXIT && check != BAD_FLAG)
    hello(p, opts);
  
  MPI_Finalize();
  return (check == BAD_FLAG);
}

