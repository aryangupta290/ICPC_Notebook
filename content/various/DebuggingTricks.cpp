/**
 * Author: Simon Lindholm
 * Date: 2015-03-20
 * License: CC0
 * Source: me
 * Description: Debug
 * Time: O(k\log\frac{n}{k})
 * Status: tested
 */
1. signal(SIGSEGV, [](int) { _Exit(0); });
converts segfaults into Wrong Answers. Similarly one can catch SIGABRT (assertion failures) and SIGFPE (zero divisions). _GLIBCXX_DEBUG failures generate. SIGABRT (or SIGSEGV on gcc 5.4.0 apparently).
2. feenableexcept(29); 
kills the program on NaNs(1), 0-divs (4), infinities (8) and denormals (16).