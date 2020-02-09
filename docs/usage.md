# Repo Usage

## Downloading the contest problems

* Open a terminal, e.g., Git Bash, in a directory of your choice.
* Enter `git clone https://github.com/UCLeuvenLimburg/VPW-opgaves`. This will create a subdirectory `VPW-opgaves` and download all files.

## Receiving updates

* Open a terminal inside somewhere under `VPW-opgaves`.
* Enter `git pull`.

## Receiving updates from original repository (only for admin)

* `git remote add upstream https://github.com/vlaamseprogrammeerwedstrijd/opgaves.git` (only first time)
* `git remote set-url --push upstream DISALLOWED` (only first time, as safety precaution)
* `git pull upstream master`
