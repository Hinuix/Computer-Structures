
<b>1. How much time (in miliseconds) does it take for each thread to complete its task?</b>

- <i>Single-threaded version takes: 8000 milliseconds</i>

- <i>Multi-threaded version: The main thread took 3000 milliseconds, thread 1 took 2000 milliseconds, and thread 2 took 3000 milliseconds.</i>

<b>2. In the multi-threaded version does main thread time == thread 1 time + thread 2 time</b>

 - <i>No, it runs simultaneously the main thread will be the max of the two threads.</i>

<b>3. Which method (single-thread or multi-thread) results in a faster execution time? Explain why the given version is faster than the other.</b>

- <i>Multi-thread would be faster because it runs simultaneously and not linear unlike the single-thread.</i>

<b>4. In the Step 4 - Execution section above, why are there two possible outputs for the same code?</b>

- <i>There are two outputs because one of them could finish before the other, no set order exists.</i>