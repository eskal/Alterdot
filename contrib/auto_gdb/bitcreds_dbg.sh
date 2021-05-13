#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.bitcreds/bitcredsd.pid file instead
bitcreds_pid=$(<~/.bitcreds/testnet3/bitcredsd.pid)
sudo gdb -batch -ex "source debug.gdb" bitcredsd ${bitcreds_pid}
