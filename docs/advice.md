# General Advice

* Writing text to a file/console is relatively slow and it is more efficient to output large blocks of text instead of single characters one at a time. For this reason, it often happens that your output gets stored in a temporary buffer (*caching*), which will get "flushed" only when enough data has been accumulated. This can be a problem at the contest: the server imposes a time limit, and after N seconds it kills the process running your code. This means your program does not get the chance to flush its output. If you are in a situation where the server tells you your program timed out and did not output anything, the caching is the most likely culprit. To remedy this, you need to *flush* your output.
* It might be advisable that you use a programming language that all three members know.
* Develop some small libraries, e.g., functions specialized in reading data from STDIN.

## Language Specific Tips

* [Java](docs/java.md)
* [Python](docs/python.md)
