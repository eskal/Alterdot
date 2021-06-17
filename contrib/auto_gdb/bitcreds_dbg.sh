#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.alterdot/alterdotd.pid file instead
alterdot_pid=$(<~/.alterdot/testnet3/alterdotd.pid)
sudo gdb -batch -ex "source debug.gdb" alterdotd ${alterdot_pid}
