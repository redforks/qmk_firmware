cat ./keyboards/ergodone/keymaps/my/keymap.header > ./keyboards/ergodone/keymaps/my/keymap.c
docker run --rm -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container bin/qmk json2c ergodone_layout_ergodox_mine.json | tail -n +2 >> ./keyboards/ergodone/keymaps/my/keymap.c

./util/docker_build.sh ergodone:my
