# powerline-c

This is a simple and fast powerline for your shell, made in good old C.

No git integration, no plugins, just the fastest, simplest powerline you can ever imagine.

`powerline-c` is a rewrite of [powerline-shell](https://github.com/b-ryan/powerline-shell), inspired by [powerline-go](https://github.com/justjanne/powerline-go) and by [powerline-rs](https://github.com/jD91mZM2/powerline-rs).

## Why?

 - Faster than any powerline because it's pure vanilla C.
 - No need to download the Rust or Go runtime.
 - Native.
 - It's really really fast. You won't wait a millisecond.
 
## Okay, where's the catch?

Well, there isn't. Except that there is no git functionnality or anything like that.

That would make it slow. And we don't want that.

So yeah. Enjoy!

## Installation

You'll need CMake and a working C compiler. That's all.

```sh

git clone https://github.com/Myuujinn/powerline-c.git
cd powerline-c
cmake .
cmake --build .
sudo cmake --build . --target install

```
powerline-c will be installed in /usr/local/bin.
Then add it to your shell.

# Add it to your shell

## Fish

```fish
function fish_prompt
    powerline-c $status
end
```
