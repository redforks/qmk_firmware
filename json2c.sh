cat ./keyboards/bm40hsrgb/keymaps/my/keymap.header > ./keyboards/bm40hsrgb/keymaps/my/keymap.c

docker run --rm -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container bin/qmk json2c bm40hsrgb_layout_planck_mit_mine.json | tail -n +2 >> ./keyboards/bm40hsrgb/keymaps/my/keymap.c

sed -i 's/HYPR(KC_Y)/VIM_YANK/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c
sed -i 's/HYPR(KC_P)/VIM_PASTE/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c
