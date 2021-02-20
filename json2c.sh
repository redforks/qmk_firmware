docker run --rm -w /qmk_firmware/ -v "$PWD":/qmk_firmware --user $(id -u):$(id -g) qmkfm/base_container bin/qmk json2c bm40hsrgb_layout_planck_mit_mine.json | tail -n +2 > ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp

sed -i 's/HYPR(KC_Y)/VIM_YANK/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_P)/VIM_PASTE/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_T)/PHP_THIS/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_A)/PHP_ARROW/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_S)/PHP_SELF/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_K)/KENNER_DB/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/HYPR(KC_D)/KENNER_CRM/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/\bKC_P\b/TD(TD_PP)/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/\bKC_R\b/TD(TD_RR)/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp
sed -i 's/\bKC_F\b/TD(TD_FF)/' ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp

cat ./keyboards/bm40hsrgb/keymaps/my/keymap.header > ./keyboards/bm40hsrgb/keymaps/my/keymap.c
cat ./keyboards/bm40hsrgb/keymaps/my/keymap.c.tmp >> ./keyboards/bm40hsrgb/keymaps/my/keymap.c
