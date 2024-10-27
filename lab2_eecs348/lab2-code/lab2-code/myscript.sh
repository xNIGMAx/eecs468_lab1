#!/bin/bash

for user in "$@"; do
    if [ "$user" = "Mahdi" ]; then
        echo "Hello main user, $user"
    else
        echo "$user!!!, You are not allowed access!"
    fi
done

