.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240704_C3B114
/* C3B114 80240704 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3B118 80240708 AFB40048 */  sw        $s4, 0x48($sp)
/* C3B11C 8024070C 0080A02D */  daddu     $s4, $a0, $zero
/* C3B120 80240710 AFBF004C */  sw        $ra, 0x4c($sp)
/* C3B124 80240714 AFB30044 */  sw        $s3, 0x44($sp)
/* C3B128 80240718 AFB20040 */  sw        $s2, 0x40($sp)
/* C3B12C 8024071C AFB1003C */  sw        $s1, 0x3c($sp)
/* C3B130 80240720 AFB00038 */  sw        $s0, 0x38($sp)
/* C3B134 80240724 8E930148 */  lw        $s3, 0x148($s4)
/* C3B138 80240728 00C0802D */  daddu     $s0, $a2, $zero
/* C3B13C 8024072C 86640008 */  lh        $a0, 8($s3)
/* C3B140 80240730 0C00EABB */  jal       get_npc_unsafe
/* C3B144 80240734 0000902D */   daddu    $s2, $zero, $zero
/* C3B148 80240738 0C039D59 */  jal       get_player_data
/* C3B14C 8024073C 0040882D */   daddu    $s1, $v0, $zero
/* C3B150 80240740 0200202D */  daddu     $a0, $s0, $zero
/* C3B154 80240744 0260282D */  daddu     $a1, $s3, $zero
/* C3B158 80240748 0000382D */  daddu     $a3, $zero, $zero
/* C3B15C 8024074C 3C0642A0 */  lui       $a2, 0x42a0
/* C3B160 80240750 0040802D */  daddu     $s0, $v0, $zero
/* C3B164 80240754 0C01242D */  jal       func_800490B4
/* C3B168 80240758 AFA00010 */   sw       $zero, 0x10($sp)
/* C3B16C 8024075C 10400022 */  beqz      $v0, .L802407E8
/* C3B170 80240760 00000000 */   nop
/* C3B174 80240764 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C3B178 80240768 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3B17C 8024076C 804300B4 */  lb        $v1, 0xb4($v0)
/* C3B180 80240770 24020002 */  addiu     $v0, $zero, 2
/* C3B184 80240774 10620013 */  beq       $v1, $v0, .L802407C4
/* C3B188 80240778 2402001A */   addiu    $v0, $zero, 0x1a
/* C3B18C 8024077C 10620011 */  beq       $v1, $v0, .L802407C4
/* C3B190 80240780 24020003 */   addiu    $v0, $zero, 3
/* C3B194 80240784 1062000F */  beq       $v1, $v0, .L802407C4
/* C3B198 80240788 2402000E */   addiu    $v0, $zero, 0xe
/* C3B19C 8024078C 1062000D */  beq       $v1, $v0, .L802407C4
/* C3B1A0 80240790 24020010 */   addiu    $v0, $zero, 0x10
/* C3B1A4 80240794 1062000B */  beq       $v1, $v0, .L802407C4
/* C3B1A8 80240798 2402000B */   addiu    $v0, $zero, 0xb
/* C3B1AC 8024079C 10620009 */  beq       $v1, $v0, .L802407C4
/* C3B1B0 802407A0 2402000A */   addiu    $v0, $zero, 0xa
/* C3B1B4 802407A4 10620007 */  beq       $v1, $v0, .L802407C4
/* C3B1B8 802407A8 24020012 */   addiu    $v0, $zero, 0x12
/* C3B1BC 802407AC 10620005 */  beq       $v1, $v0, .L802407C4
/* C3B1C0 802407B0 24020013 */   addiu    $v0, $zero, 0x13
/* C3B1C4 802407B4 10620003 */  beq       $v1, $v0, .L802407C4
/* C3B1C8 802407B8 24020025 */   addiu    $v0, $zero, 0x25
/* C3B1CC 802407BC 14620002 */  bne       $v1, $v0, .L802407C8
/* C3B1D0 802407C0 00000000 */   nop
.L802407C4:
/* C3B1D4 802407C4 24120001 */  addiu     $s2, $zero, 1
.L802407C8:
/* C3B1D8 802407C8 82030012 */  lb        $v1, 0x12($s0)
/* C3B1DC 802407CC 24020002 */  addiu     $v0, $zero, 2
/* C3B1E0 802407D0 14620007 */  bne       $v1, $v0, .L802407F0
/* C3B1E4 802407D4 24020001 */   addiu    $v0, $zero, 1
/* C3B1E8 802407D8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C3B1EC 802407DC 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C3B1F0 802407E0 50430002 */  beql      $v0, $v1, .L802407EC
/* C3B1F4 802407E4 24120001 */   addiu    $s2, $zero, 1
.L802407E8:
/* C3B1F8 802407E8 82030012 */  lb        $v1, 0x12($s0)
.L802407EC:
/* C3B1FC 802407EC 24020001 */  addiu     $v0, $zero, 1
.L802407F0:
/* C3B200 802407F0 14620006 */  bne       $v1, $v0, .L8024080C
/* C3B204 802407F4 24020003 */   addiu    $v0, $zero, 3
/* C3B208 802407F8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C3B20C 802407FC 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C3B210 80240800 14400008 */  bnez      $v0, .L80240824
/* C3B214 80240804 27A40028 */   addiu    $a0, $sp, 0x28
/* C3B218 80240808 24020003 */  addiu     $v0, $zero, 3
.L8024080C:
/* C3B21C 8024080C 1462001B */  bne       $v1, $v0, .L8024087C
/* C3B220 80240810 24020002 */   addiu    $v0, $zero, 2
/* C3B224 80240814 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C3B228 80240818 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C3B22C 8024081C 14620017 */  bne       $v1, $v0, .L8024087C
/* C3B230 80240820 27A40028 */   addiu    $a0, $sp, 0x28
.L80240824:
/* C3B234 80240824 27A5002C */  addiu     $a1, $sp, 0x2c
/* C3B238 80240828 8E27000C */  lw        $a3, 0xc($s1)
/* C3B23C 8024082C C6200038 */  lwc1      $f0, 0x38($s1)
/* C3B240 80240830 C6220040 */  lwc1      $f2, 0x40($s1)
/* C3B244 80240834 0000302D */  daddu     $a2, $zero, $zero
/* C3B248 80240838 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3B24C 8024083C 0C00A7E7 */  jal       add_vec2D_polar
/* C3B250 80240840 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C3B254 80240844 3C028011 */  lui       $v0, %hi(wPartnerNpc)
/* C3B258 80240848 8C42C930 */  lw        $v0, %lo(wPartnerNpc)($v0)
/* C3B25C 8024084C C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C3B260 80240850 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C3B264 80240854 8C460038 */  lw        $a2, 0x38($v0)
/* C3B268 80240858 0C00A7B5 */  jal       dist2D
/* C3B26C 8024085C 8C470040 */   lw       $a3, 0x40($v0)
/* C3B270 80240860 3C0142A0 */  lui       $at, 0x42a0
/* C3B274 80240864 44811000 */  mtc1      $at, $f2
/* C3B278 80240868 00000000 */  nop
/* C3B27C 8024086C 4602003E */  c.le.s    $f0, $f2
/* C3B280 80240870 00000000 */  nop
/* C3B284 80240874 45030001 */  bc1tl     .L8024087C
/* C3B288 80240878 24120001 */   addiu    $s2, $zero, 1
.L8024087C:
/* C3B28C 8024087C 12400026 */  beqz      $s2, .L80240918
/* C3B290 80240880 0220202D */   daddu    $a0, $s1, $zero
/* C3B294 80240884 3C05B000 */  lui       $a1, 0xb000
/* C3B298 80240888 34A5000E */  ori       $a1, $a1, 0xe
/* C3B29C 8024088C 0C012530 */  jal       func_800494C0
/* C3B2A0 80240890 0000302D */   daddu    $a2, $zero, $zero
/* C3B2A4 80240894 0000202D */  daddu     $a0, $zero, $zero
/* C3B2A8 80240898 0220282D */  daddu     $a1, $s1, $zero
/* C3B2AC 8024089C 0000302D */  daddu     $a2, $zero, $zero
/* C3B2B0 802408A0 862200A8 */  lh        $v0, 0xa8($s1)
/* C3B2B4 802408A4 8E6300CC */  lw        $v1, 0xcc($s3)
/* C3B2B8 802408A8 3C013F80 */  lui       $at, 0x3f80
/* C3B2BC 802408AC 44810000 */  mtc1      $at, $f0
/* C3B2C0 802408B0 3C014000 */  lui       $at, 0x4000
/* C3B2C4 802408B4 44811000 */  mtc1      $at, $f2
/* C3B2C8 802408B8 3C01C1A0 */  lui       $at, 0xc1a0
/* C3B2CC 802408BC 44812000 */  mtc1      $at, $f4
/* C3B2D0 802408C0 44823000 */  mtc1      $v0, $f6
/* C3B2D4 802408C4 00000000 */  nop
/* C3B2D8 802408C8 468031A0 */  cvt.s.w   $f6, $f6
/* C3B2DC 802408CC 44073000 */  mfc1      $a3, $f6
/* C3B2E0 802408D0 8C63002C */  lw        $v1, 0x2c($v1)
/* C3B2E4 802408D4 2402000A */  addiu     $v0, $zero, 0xa
/* C3B2E8 802408D8 A622008E */  sh        $v0, 0x8e($s1)
/* C3B2EC 802408DC 2402000F */  addiu     $v0, $zero, 0xf
/* C3B2F0 802408E0 AE230028 */  sw        $v1, 0x28($s1)
/* C3B2F4 802408E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* C3B2F8 802408E8 27A20030 */  addiu     $v0, $sp, 0x30
/* C3B2FC 802408EC E7A00010 */  swc1      $f0, 0x10($sp)
/* C3B300 802408F0 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3B304 802408F4 E7A40018 */  swc1      $f4, 0x18($sp)
/* C3B308 802408F8 0C01BFA4 */  jal       fx_emote
/* C3B30C 802408FC AFA20020 */   sw       $v0, 0x20($sp)
/* C3B310 80240900 0220202D */  daddu     $a0, $s1, $zero
/* C3B314 80240904 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C3B318 80240908 0C012530 */  jal       func_800494C0
/* C3B31C 8024090C 3C060020 */   lui      $a2, 0x20
/* C3B320 80240910 24020002 */  addiu     $v0, $zero, 2
/* C3B324 80240914 AE820070 */  sw        $v0, 0x70($s4)
.L80240918:
/* C3B328 80240918 9622008E */  lhu       $v0, 0x8e($s1)
/* C3B32C 8024091C 24420001 */  addiu     $v0, $v0, 1
/* C3B330 80240920 A622008E */  sh        $v0, 0x8e($s1)
/* C3B334 80240924 00021400 */  sll       $v0, $v0, 0x10
/* C3B338 80240928 00021C03 */  sra       $v1, $v0, 0x10
/* C3B33C 8024092C 2402001B */  addiu     $v0, $zero, 0x1b
/* C3B340 80240930 14620005 */  bne       $v1, $v0, .L80240948
/* C3B344 80240934 24020039 */   addiu    $v0, $zero, 0x39
/* C3B348 80240938 0220202D */  daddu     $a0, $s1, $zero
/* C3B34C 8024093C 3C05B000 */  lui       $a1, 0xb000
/* C3B350 80240940 08090257 */  j         .L8024095C
/* C3B354 80240944 34A5000C */   ori      $a1, $a1, 0xc
.L80240948:
/* C3B358 80240948 14620008 */  bne       $v1, $v0, .L8024096C
/* C3B35C 8024094C 2402003B */   addiu    $v0, $zero, 0x3b
/* C3B360 80240950 0220202D */  daddu     $a0, $s1, $zero
/* C3B364 80240954 3C05B000 */  lui       $a1, 0xb000
/* C3B368 80240958 34A5000D */  ori       $a1, $a1, 0xd
.L8024095C:
/* C3B36C 8024095C 0C012530 */  jal       func_800494C0
/* C3B370 80240960 0000302D */   daddu    $a2, $zero, $zero
/* C3B374 80240964 08090267 */  j         .L8024099C
/* C3B378 80240968 00000000 */   nop
.L8024096C:
/* C3B37C 8024096C 14620005 */  bne       $v1, $v0, .L80240984
/* C3B380 80240970 2402003C */   addiu    $v0, $zero, 0x3c
/* C3B384 80240974 8E6200CC */  lw        $v0, 0xcc($s3)
/* C3B388 80240978 8C420030 */  lw        $v0, 0x30($v0)
/* C3B38C 8024097C 08090267 */  j         .L8024099C
/* C3B390 80240980 AE220028 */   sw       $v0, 0x28($s1)
.L80240984:
/* C3B394 80240984 14620005 */  bne       $v1, $v0, .L8024099C
/* C3B398 80240988 00000000 */   nop
/* C3B39C 8024098C 8E6200CC */  lw        $v0, 0xcc($s3)
/* C3B3A0 80240990 8C420028 */  lw        $v0, 0x28($v0)
/* C3B3A4 80240994 A620008E */  sh        $zero, 0x8e($s1)
/* C3B3A8 80240998 AE220028 */  sw        $v0, 0x28($s1)
.L8024099C:
/* C3B3AC 8024099C 8FBF004C */  lw        $ra, 0x4c($sp)
/* C3B3B0 802409A0 8FB40048 */  lw        $s4, 0x48($sp)
/* C3B3B4 802409A4 8FB30044 */  lw        $s3, 0x44($sp)
/* C3B3B8 802409A8 8FB20040 */  lw        $s2, 0x40($sp)
/* C3B3BC 802409AC 8FB1003C */  lw        $s1, 0x3c($sp)
/* C3B3C0 802409B0 8FB00038 */  lw        $s0, 0x38($sp)
/* C3B3C4 802409B4 03E00008 */  jr        $ra
/* C3B3C8 802409B8 27BD0050 */   addiu    $sp, $sp, 0x50