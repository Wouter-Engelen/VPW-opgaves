# Python-Specific Advice

## Reading From STDIN

```python
# Reading next line as a string
line = input()

# Reading next line as an integer
n = int(input())

# Reading next line as a list of integers
ns = [ int(x) for x in input().split(' ') ]
```

## Flushing

```python
import sys

sys.stdout.flush()
```

or

```python
print(whatever, flush=True)
```

## Command Line

```bash
# Uitvoer solver laten afprinten
$ cat voorbeeld.invoer | python solver.py

# Uitvoer solver vergelijken met verwachte uitvoer
$ cat voorbeeld.invoer | python solver.py | diff -w - voorbeeld.uitvoer
```
