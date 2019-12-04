#pragma once

void dohup();

#define __NR_splice 340
# if !HAVE_DECL_SPLICE
#   define splice(fdin, off_in, fdout, off_out, len, flags) syscall(__NR_splice, fdin, off_in, fdout, off_out, len, flags)
#  endif

#define __NR_accept4 366
# if !HAVE_DECL_ACCEPT4
#   define accept4(sockfd, addr, addrlen, flags) syscall(__NR_accept4, sockfd, addr, addrlen, flags)
#  endif

# ifndef SYNC_FILE_RANGE_WRITE
#  include <linux/fs.h>
# endif

# ifndef SPLICE_F_MOVE
#  define SPLICE_F_MOVE        1       /* Move pages instead of copying.  */
# endif

# ifndef SPLICE_F_NONBLOCK
#  define SPLICE_F_NONBLOCK    2       /* Don't block on the pipe splicing
                                         (but we may still block on the fd
                                         we splice from/to).  */
# endif

# ifndef SPLICE_F_MORE
#  define SPLICE_F_MORE        4       /* Expect more data.  */
# endif

# ifndef SPLICE_F_GIFT
#  define SPLICE_F_GIFT                8       /* Pages passed in are a gift.  */
# endif
