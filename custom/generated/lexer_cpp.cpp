#if !defined(FCODER_LEX_GEN_HAND_WRITTEN)
#define FCODER_LEX_GEN_HAND_WRITTEN

internal u64
lexeme_hash(u64 seed, u8 *ptr, u64 size){
  u64 result = 0;
  for (u64 i = 0; i < size; i += 1, ptr += 1){
    result ^= ((*ptr) ^ result*59) + seed;
  }
  return(result);
}

internal Lexeme_Table_Lookup
lexeme_table_lookup(u64 *hash_array, String_Const_u8 *key_array,
                    Lexeme_Table_Value *value_array, i32 slot_count, u64 seed,
                    u8 *ptr, u64 size){
  Lexeme_Table_Lookup result = {};
  u64 hash = lexeme_hash(seed, ptr, size);
  u64 comparison_hash = hash | 1;
  i32 first_index = (hash % slot_count);
  i32 index = first_index;
  for (;;){
    if (hash_array[index] == comparison_hash){
      if (string_match(SCu8(ptr, size), key_array[index])){
        result.found_match = true;
        result.base_kind = value_array[index].base_kind;
        result.sub_kind = value_array[index].sub_kind;
        break;
      }
    }
    else if (hash_array[index] == 0){
      break;
    }
    index += 1;
    if (index == slot_count){
      index = 0;
    }
    if (index == first_index){
      break;
    }
  }
  return(result);
}

#endif
u64 cpp_main_keys_hash_array[146] = {
  0x48c8f28842f59c47,0x0000000000000000,0xbab8a262c4df5a37,0x0000000000000000,
  0x0000000000000000,0xb9bbed97f1056703,0x48c8f28842df278d,0xbab1bef7562ef041,
  0xbabf34ecf9c9b92d,0x6ad9a319b66a4ff7,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0x00f052840ff7b1e1,0x0000000000000000,0x48c8f28842b28161,
  0x48c8f28842ad9b45,0x30393661d6c33d71,0xe98391e5fbbdbee9,0xb9bbeda9d6d0c641,
  0x0000000000000000,0xbabf34e507676e41,0x0000000000000000,0x0000000000000000,
  0xe9839187329296af,0x0000000000000000,0x48c8f2884281acbf,0x48c8f28b8bbbe459,
  0x00f05284020de255,0x0000000000000000,0x0000000000000000,0x0000000000000000,
  0xbab1b0c5cbbc945f,0x0000000000000000,0x0000000000000000,0x6ad9a319b669ca0b,
  0x326eaef8a6a2057f,0x0000000000000000,0xbab8b77928e23cef,0x6ad9a319b6690671,
  0x00f05284106c19f5,0x0000000000000000,0x0000000000000000,0xe98396956ecdb92d,
  0x00f0528410c0f929,0x0000000000000000,0x0000000000000000,0xb9bbed90d3d86a6d,
  0x0000000000000000,0x30396a0fba146b2d,0x48c8f28842f5a507,0xf3630402036fad3d,
  0x0000000000000000,0xbabf34ecfa10842d,0xb9bbed900af055f7,0x6ad9a319b669e2a5,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0x8d911662765857bd,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0xef7c11b4107c208d,
  0xbab89c536590e987,0xe98397793c216a6d,0x48c8f28842d822bf,0x0000000000000000,
  0xb9bbed97fe0c59af,0xe98396956e0e676d,0x0000000000000000,0xb9bbed97438b2229,
  0x6ad9a319b66ae23b,0x0000000000000000,0x0000000000000000,0xc6f60fe589e6ba8d,
  0xbabf372a5553ea3f,0x0000000000000000,0xe98391bb5e07f765,0xb9bbeda99b013391,
  0x0000000000000000,0xe983913b79d597f1,0x0000000000000000,0x6759efa683b80a99,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0x00f05284106b10f5,
  0x00f052840ee88c4f,0xb9bbed97f4d43425,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0xb9bbeda9d6dcb927,0xe98396939e58af1b,0x0000000000000000,
  0x00f052840bad90ef,0xb9bbed9029134ad5,0xbab8a2e42d28a4d1,0x00f052847cb29c65,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0xe9836d123891be43,
  0xbab198fc0e04254f,0xb9bbed97719d7505,0x0000000000000000,0xb9bbeda9d6dc8275,
  0x00f052840fa122c7,0x0000000000000000,0x48c8f28842c72bfd,0xbab8ce9100c0660b,
  0xb9bbed90d43c82d7,0x00f052841a77558d,0x0000000000000000,0xf3630402036fae13,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0xb9bbed977ca69e4d,
  0x0000000000000000,0x0000000000000000,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0x3145467e4bbf8cf3,0xe98391bb5e07e8bf,0x48c8f28842db5d5d,
  0x48c8f2884286fba5,0xe98396956e0e842d,0x0000000000000000,0xed9abfbe19235a8d,
  0x0000000000000000,0x48c8f28842dac367,0x0000000000000000,0xbabf34ecfa10676d,
  0xb9bbed9560fb6a95,0xb9bbed999c961f83,0x0000000000000000,0x0000000000000000,
  0x0000000000000000,0xa53d30b5faf1fa8d,
};
u8 cpp_main_keys_key_array_0[] = {0x65,0x6c,0x73,0x65,};
u8 cpp_main_keys_key_array_2[] = {0x64,0x65,0x63,0x6c,0x74,0x79,0x70,0x65,};
u8 cpp_main_keys_key_array_5[] = {0x65,0x78,0x74,0x65,0x72,0x6e,};
u8 cpp_main_keys_key_array_6[] = {0x6c,0x6f,0x6e,0x67,};
u8 cpp_main_keys_key_array_7[] = {0x6e,0x6f,0x65,0x78,0x63,0x65,0x70,0x74,};
u8 cpp_main_keys_key_array_8[] = {0x75,0x69,0x6e,0x74,0x36,0x34,0x5f,0x74,};
u8 cpp_main_keys_key_array_9[] = {0x61,0x73,0x6d,};
u8 cpp_main_keys_key_array_13[] = {0x66,0x6c,0x6f,0x61,0x74,};
u8 cpp_main_keys_key_array_15[] = {0x76,0x6f,0x69,0x64,};
u8 cpp_main_keys_key_array_16[] = {0x61,0x75,0x74,0x6f,};
u8 cpp_main_keys_key_array_17[] = {0x70,0x72,0x6f,0x74,0x65,0x63,0x74,0x65,0x64,};
u8 cpp_main_keys_key_array_18[] = {0x76,0x69,0x72,0x74,0x75,0x61,0x6c,};
u8 cpp_main_keys_key_array_19[] = {0x73,0x69,0x67,0x6e,0x65,0x64,};
u8 cpp_main_keys_key_array_21[] = {0x75,0x6e,0x73,0x69,0x67,0x6e,0x65,0x64,};
u8 cpp_main_keys_key_array_24[] = {0x70,0x72,0x69,0x76,0x61,0x74,0x65,};
u8 cpp_main_keys_key_array_26[] = {0x74,0x72,0x75,0x65,};
u8 cpp_main_keys_key_array_27[] = {0x4e,0x55,0x4c,0x4c,};
u8 cpp_main_keys_key_array_28[] = {0x75,0x73,0x69,0x6e,0x67,};
u8 cpp_main_keys_key_array_32[] = {0x74,0x79,0x70,0x65,0x6e,0x61,0x6d,0x65,};
u8 cpp_main_keys_key_array_35[] = {0x66,0x6f,0x72,};
u8 cpp_main_keys_key_array_36[] = {0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,};
u8 cpp_main_keys_key_array_38[] = {0x76,0x6f,0x6c,0x61,0x74,0x69,0x6c,0x65,};
u8 cpp_main_keys_key_array_39[] = {0x6e,0x65,0x77,};
u8 cpp_main_keys_key_array_40[] = {0x63,0x6c,0x61,0x73,0x73,};
u8 cpp_main_keys_key_array_43[] = {0x69,0x6e,0x74,0x36,0x34,0x5f,0x74,};
u8 cpp_main_keys_key_array_44[] = {0x63,0x61,0x74,0x63,0x68,};
u8 cpp_main_keys_key_array_47[] = {0x69,0x6e,0x74,0x38,0x5f,0x74,};
u8 cpp_main_keys_key_array_49[] = {0x70,0x74,0x72,0x64,0x69,0x66,0x66,0x5f,0x74,};
u8 cpp_main_keys_key_array_50[] = {0x65,0x6e,0x75,0x6d,};
u8 cpp_main_keys_key_array_51[] = {0x64,0x6f,};
u8 cpp_main_keys_key_array_53[] = {0x75,0x69,0x6e,0x74,0x31,0x36,0x5f,0x74,};
u8 cpp_main_keys_key_array_54[] = {0x64,0x6f,0x75,0x62,0x6c,0x65,};
u8 cpp_main_keys_key_array_55[] = {0x69,0x6e,0x74,};
u8 cpp_main_keys_key_array_61[] = {0x73,0x74,0x61,0x74,0x69,0x63,0x5f,0x61,0x73,0x73,0x65,0x72,0x74,};
u8 cpp_main_keys_key_array_67[] = {0x72,0x65,0x69,0x6e,0x74,0x65,0x72,0x70,0x72,0x65,0x74,0x5f,0x63,0x61,0x73,0x74,};
u8 cpp_main_keys_key_array_68[] = {0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,};
u8 cpp_main_keys_key_array_69[] = {0x75,0x69,0x6e,0x74,0x38,0x5f,0x74,};
u8 cpp_main_keys_key_array_70[] = {0x63,0x61,0x73,0x65,};
u8 cpp_main_keys_key_array_72[] = {0x64,0x65,0x6c,0x65,0x74,0x65,};
u8 cpp_main_keys_key_array_73[] = {0x69,0x6e,0x74,0x33,0x32,0x5f,0x74,};
u8 cpp_main_keys_key_array_75[] = {0x73,0x77,0x69,0x74,0x63,0x68,};
u8 cpp_main_keys_key_array_76[] = {0x74,0x72,0x79,};
u8 cpp_main_keys_key_array_79[] = {0x73,0x74,0x61,0x74,0x69,0x63,0x5f,0x63,0x61,0x73,0x74,};
u8 cpp_main_keys_key_array_80[] = {0x63,0x6f,0x6e,0x74,0x69,0x6e,0x75,0x65,};
u8 cpp_main_keys_key_array_82[] = {0x61,0x6c,0x69,0x67,0x6e,0x61,0x73,};
u8 cpp_main_keys_key_array_83[] = {0x74,0x79,0x70,0x65,0x69,0x64,};
u8 cpp_main_keys_key_array_85[] = {0x64,0x65,0x66,0x61,0x75,0x6c,0x74,};
u8 cpp_main_keys_key_array_87[] = {0x74,0x68,0x72,0x65,0x61,0x64,0x5f,0x6c,0x6f,0x63,0x61,0x6c,};
u8 cpp_main_keys_key_array_91[] = {0x63,0x6f,0x6e,0x73,0x74,};
u8 cpp_main_keys_key_array_92[] = {0x75,0x6e,0x69,0x6f,0x6e,};
u8 cpp_main_keys_key_array_93[] = {0x65,0x78,0x70,0x6f,0x72,0x74,};
u8 cpp_main_keys_key_array_97[] = {0x73,0x69,0x7a,0x65,0x6f,0x66,};
u8 cpp_main_keys_key_array_98[] = {0x6e,0x75,0x6c,0x6c,0x70,0x74,0x72,};
u8 cpp_main_keys_key_array_100[] = {0x77,0x68,0x69,0x6c,0x65,};
u8 cpp_main_keys_key_array_101[] = {0x66,0x72,0x69,0x65,0x6e,0x64,};
u8 cpp_main_keys_key_array_102[] = {0x65,0x78,0x70,0x6c,0x69,0x63,0x69,0x74,};
u8 cpp_main_keys_key_array_103[] = {0x73,0x68,0x6f,0x72,0x74,};
u8 cpp_main_keys_key_array_107[] = {0x74,0x79,0x70,0x65,0x64,0x65,0x66,};
u8 cpp_main_keys_key_array_108[] = {0x74,0x65,0x6d,0x70,0x6c,0x61,0x74,0x65,};
u8 cpp_main_keys_key_array_109[] = {0x73,0x74,0x61,0x74,0x69,0x63,};
u8 cpp_main_keys_key_array_111[] = {0x73,0x69,0x7a,0x65,0x5f,0x74,};
u8 cpp_main_keys_key_array_112[] = {0x66,0x61,0x6c,0x73,0x65,};
u8 cpp_main_keys_key_array_114[] = {0x67,0x6f,0x74,0x6f,};
u8 cpp_main_keys_key_array_115[] = {0x6f,0x70,0x65,0x72,0x61,0x74,0x6f,0x72,};
u8 cpp_main_keys_key_array_116[] = {0x69,0x6e,0x6c,0x69,0x6e,0x65,};
u8 cpp_main_keys_key_array_117[] = {0x62,0x72,0x65,0x61,0x6b,};
u8 cpp_main_keys_key_array_119[] = {0x69,0x66,};
u8 cpp_main_keys_key_array_123[] = {0x73,0x74,0x72,0x75,0x63,0x74,};
u8 cpp_main_keys_key_array_129[] = {0x63,0x6f,0x6e,0x73,0x74,0x65,0x78,0x70,0x72,};
u8 cpp_main_keys_key_array_130[] = {0x61,0x6c,0x69,0x67,0x6e,0x6f,0x66,};
u8 cpp_main_keys_key_array_131[] = {0x62,0x6f,0x6f,0x6c,};
u8 cpp_main_keys_key_array_132[] = {0x74,0x68,0x69,0x73,};
u8 cpp_main_keys_key_array_133[] = {0x69,0x6e,0x74,0x31,0x36,0x5f,0x74,};
u8 cpp_main_keys_key_array_135[] = {0x63,0x6f,0x6e,0x73,0x74,0x5f,0x63,0x61,0x73,0x74,};
u8 cpp_main_keys_key_array_137[] = {0x63,0x68,0x61,0x72,};
u8 cpp_main_keys_key_array_139[] = {0x75,0x69,0x6e,0x74,0x33,0x32,0x5f,0x74,};
u8 cpp_main_keys_key_array_140[] = {0x70,0x75,0x62,0x6c,0x69,0x63,};
u8 cpp_main_keys_key_array_141[] = {0x72,0x65,0x74,0x75,0x72,0x6e,};
u8 cpp_main_keys_key_array_145[] = {0x64,0x79,0x6e,0x61,0x6d,0x69,0x63,0x5f,0x63,0x61,0x73,0x74,};
String_Const_u8 cpp_main_keys_key_array[146] = {
  {cpp_main_keys_key_array_0, 4},
  {0, 0},
  {cpp_main_keys_key_array_2, 8},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_5, 6},
  {cpp_main_keys_key_array_6, 4},
  {cpp_main_keys_key_array_7, 8},
  {cpp_main_keys_key_array_8, 8},
  {cpp_main_keys_key_array_9, 3},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_13, 5},
  {0, 0},
  {cpp_main_keys_key_array_15, 4},
  {cpp_main_keys_key_array_16, 4},
  {cpp_main_keys_key_array_17, 9},
  {cpp_main_keys_key_array_18, 7},
  {cpp_main_keys_key_array_19, 6},
  {0, 0},
  {cpp_main_keys_key_array_21, 8},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_24, 7},
  {0, 0},
  {cpp_main_keys_key_array_26, 4},
  {cpp_main_keys_key_array_27, 4},
  {cpp_main_keys_key_array_28, 5},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_32, 8},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_35, 3},
  {cpp_main_keys_key_array_36, 9},
  {0, 0},
  {cpp_main_keys_key_array_38, 8},
  {cpp_main_keys_key_array_39, 3},
  {cpp_main_keys_key_array_40, 5},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_43, 7},
  {cpp_main_keys_key_array_44, 5},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_47, 6},
  {0, 0},
  {cpp_main_keys_key_array_49, 9},
  {cpp_main_keys_key_array_50, 4},
  {cpp_main_keys_key_array_51, 2},
  {0, 0},
  {cpp_main_keys_key_array_53, 8},
  {cpp_main_keys_key_array_54, 6},
  {cpp_main_keys_key_array_55, 3},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_61, 13},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_67, 16},
  {cpp_main_keys_key_array_68, 8},
  {cpp_main_keys_key_array_69, 7},
  {cpp_main_keys_key_array_70, 4},
  {0, 0},
  {cpp_main_keys_key_array_72, 6},
  {cpp_main_keys_key_array_73, 7},
  {0, 0},
  {cpp_main_keys_key_array_75, 6},
  {cpp_main_keys_key_array_76, 3},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_79, 11},
  {cpp_main_keys_key_array_80, 8},
  {0, 0},
  {cpp_main_keys_key_array_82, 7},
  {cpp_main_keys_key_array_83, 6},
  {0, 0},
  {cpp_main_keys_key_array_85, 7},
  {0, 0},
  {cpp_main_keys_key_array_87, 12},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_91, 5},
  {cpp_main_keys_key_array_92, 5},
  {cpp_main_keys_key_array_93, 6},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_97, 6},
  {cpp_main_keys_key_array_98, 7},
  {0, 0},
  {cpp_main_keys_key_array_100, 5},
  {cpp_main_keys_key_array_101, 6},
  {cpp_main_keys_key_array_102, 8},
  {cpp_main_keys_key_array_103, 5},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_107, 7},
  {cpp_main_keys_key_array_108, 8},
  {cpp_main_keys_key_array_109, 6},
  {0, 0},
  {cpp_main_keys_key_array_111, 6},
  {cpp_main_keys_key_array_112, 5},
  {0, 0},
  {cpp_main_keys_key_array_114, 4},
  {cpp_main_keys_key_array_115, 8},
  {cpp_main_keys_key_array_116, 6},
  {cpp_main_keys_key_array_117, 5},
  {0, 0},
  {cpp_main_keys_key_array_119, 2},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_123, 6},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_129, 9},
  {cpp_main_keys_key_array_130, 7},
  {cpp_main_keys_key_array_131, 4},
  {cpp_main_keys_key_array_132, 4},
  {cpp_main_keys_key_array_133, 7},
  {0, 0},
  {cpp_main_keys_key_array_135, 10},
  {0, 0},
  {cpp_main_keys_key_array_137, 4},
  {0, 0},
  {cpp_main_keys_key_array_139, 8},
  {cpp_main_keys_key_array_140, 6},
  {cpp_main_keys_key_array_141, 6},
  {0, 0},
  {0, 0},
  {0, 0},
  {cpp_main_keys_key_array_145, 12},
};
Lexeme_Table_Value cpp_main_keys_value_array[146] = {
  {17, TokenCppKind_Else},
  {0, 0},
  {4, TokenCppKind_DeclType},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_Extern},
  {16, TokenCppKind_Long},
  {4, TokenCppKind_NoExcept},
  {16, TokenCppKind_uint64_t},
  {4, TokenCppKind_Asm},
  {0, 0},
  {0, 0},
  {0, 0},
  {16, TokenCppKind_Float},
  {0, 0},
  {16, TokenCppKind_Void},
  {16, TokenCppKind_Auto},
  {4, TokenCppKind_Protected},
  {4, TokenCppKind_Virtual},
  {16, TokenCppKind_Signed},
  {0, 0},
  {16, TokenCppKind_Unsigned},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_Private},
  {0, 0},
  {8, TokenCppKind_LiteralTrue},
  {8, TokenCppKind_LiteralNull},
  {4, TokenCppKind_Using},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_Typename},
  {0, 0},
  {0, 0},
  {17, TokenCppKind_For},
  {4, TokenCppKind_Namespace},
  {0, 0},
  {4, TokenCppKind_Volatile},
  {4, TokenCppKind_New},
  {18, TokenCppKind_Class},
  {0, 0},
  {0, 0},
  {16, TokenCppKind_int64_t},
  {17, TokenCppKind_Catch},
  {0, 0},
  {0, 0},
  {16, TokenCppKind_int8_t},
  {0, 0},
  {16, TokenCppKind_ptrdiff_t},
  {18, TokenCppKind_Enum},
  {17, TokenCppKind_Do},
  {0, 0},
  {16, TokenCppKind_uint16_t},
  {16, TokenCppKind_Double},
  {16, TokenCppKind_Int},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_StaticAssert},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_ReinterpretCast},
  {4, TokenCppKind_Register},
  {16, TokenCppKind_uint8_t},
  {17, TokenCppKind_Case},
  {0, 0},
  {4, TokenCppKind_Delete},
  {16, TokenCppKind_int32_t},
  {0, 0},
  {17, TokenCppKind_Switch},
  {17, TokenCppKind_Try},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_StaticCast},
  {17, TokenCppKind_Continue},
  {0, 0},
  {4, TokenCppKind_AlignAs},
  {4, TokenCppKind_TypeID},
  {0, 0},
  {17, TokenCppKind_Default},
  {0, 0},
  {4, TokenCppKind_ThreadLocal},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_Const},
  {18, TokenCppKind_Union},
  {4, TokenCppKind_Export},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_SizeOf},
  {8, TokenCppKind_NullPtr},
  {0, 0},
  {17, TokenCppKind_While},
  {4, TokenCppKind_Friend},
  {4, TokenCppKind_Explicit},
  {16, TokenCppKind_Short},
  {0, 0},
  {0, 0},
  {0, 0},
  {18, TokenCppKind_Typedef},
  {4, TokenCppKind_Template},
  {4, TokenCppKind_Static},
  {0, 0},
  {16, TokenCppKind_size_t},
  {8, TokenCppKind_LiteralFalse},
  {0, 0},
  {17, TokenCppKind_Goto},
  {4, TokenCppKind_Operator},
  {4, TokenCppKind_Inline},
  {17, TokenCppKind_Break},
  {0, 0},
  {17, TokenCppKind_If},
  {0, 0},
  {0, 0},
  {0, 0},
  {18, TokenCppKind_Struct},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_ConstExpr},
  {4, TokenCppKind_AlignOf},
  {16, TokenCppKind_Bool},
  {4, TokenCppKind_This},
  {16, TokenCppKind_int16_t},
  {0, 0},
  {4, TokenCppKind_ConstCast},
  {0, 0},
  {16, TokenCppKind_Char},
  {0, 0},
  {16, TokenCppKind_uint32_t},
  {4, TokenCppKind_Public},
  {17, TokenCppKind_Return},
  {0, 0},
  {0, 0},
  {0, 0},
  {4, TokenCppKind_DynamicCast},
};
i32 cpp_main_keys_slot_count = 146;
u64 cpp_main_keys_seed = 0x81e8baa4ea492c71;
u64 cpp_pp_directives_hash_array[25] = {
  0xf3ccaff84a8eb157,0x152c2f6c3ff80f5b,0x0000000000000000,0xf3ccaff8accb14db,
  0x0000000000000000,0x152c2f6c204d5821,0xc6128e4b8c5f51cf,0x502f11a29abcd47b,
  0x0000000000000000,0xf3ccaff8862b88f7,0xcb442d4510a5f4d7,0x0000000000000000,
  0x0000000000000000,0x152c2f6989faef5b,0x0000000000000000,0xf3ccae4613da946d,
  0xc611131083b734d3,0x152c2f6c3698087b,0x0000000000000000,0xcb442d4510874581,
  0x152c2f6c3762c68b,0x0000000000000000,0xcb442d451087461b,0x0000000000000000,
  0x0000000000000000,
};
u8 cpp_pp_directives_key_array_0[] = {0x64,0x65,0x66,0x69,0x6e,0x65,};
u8 cpp_pp_directives_key_array_1[] = {0x75,0x6e,0x64,0x65,0x66,};
u8 cpp_pp_directives_key_array_3[] = {0x69,0x66,0x6e,0x64,0x65,0x66,};
u8 cpp_pp_directives_key_array_5[] = {0x75,0x73,0x69,0x6e,0x67,};
u8 cpp_pp_directives_key_array_6[] = {0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,};
u8 cpp_pp_directives_key_array_7[] = {0x69,0x66,};
u8 cpp_pp_directives_key_array_9[] = {0x69,0x6d,0x70,0x6f,0x72,0x74,};
u8 cpp_pp_directives_key_array_10[] = {0x6c,0x69,0x6e,0x65,};
u8 cpp_pp_directives_key_array_13[] = {0x69,0x66,0x64,0x65,0x66,};
u8 cpp_pp_directives_key_array_15[] = {0x70,0x72,0x61,0x67,0x6d,0x61,};
u8 cpp_pp_directives_key_array_16[] = {0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,};
u8 cpp_pp_directives_key_array_17[] = {0x65,0x6e,0x64,0x69,0x66,};
u8 cpp_pp_directives_key_array_19[] = {0x65,0x6c,0x73,0x65,};
u8 cpp_pp_directives_key_array_20[] = {0x65,0x72,0x72,0x6f,0x72,};
u8 cpp_pp_directives_key_array_22[] = {0x65,0x6c,0x69,0x66,};
String_Const_u8 cpp_pp_directives_key_array[25] = {
  {cpp_pp_directives_key_array_0, 6},
  {cpp_pp_directives_key_array_1, 5},
  {0, 0},
  {cpp_pp_directives_key_array_3, 6},
  {0, 0},
  {cpp_pp_directives_key_array_5, 5},
  {cpp_pp_directives_key_array_6, 7},
  {cpp_pp_directives_key_array_7, 2},
  {0, 0},
  {cpp_pp_directives_key_array_9, 6},
  {cpp_pp_directives_key_array_10, 4},
  {0, 0},
  {0, 0},
  {cpp_pp_directives_key_array_13, 5},
  {0, 0},
  {cpp_pp_directives_key_array_15, 6},
  {cpp_pp_directives_key_array_16, 7},
  {cpp_pp_directives_key_array_17, 5},
  {0, 0},
  {cpp_pp_directives_key_array_19, 4},
  {cpp_pp_directives_key_array_20, 5},
  {0, 0},
  {cpp_pp_directives_key_array_22, 4},
  {0, 0},
  {0, 0},
};
Lexeme_Table_Value cpp_pp_directives_value_array[25] = {
  {5, TokenCppKind_PPDefine},
  {5, TokenCppKind_PPUndef},
  {0, 0},
  {5, TokenCppKind_PPIfNDef},
  {0, 0},
  {5, TokenCppKind_PPUsing},
  {5, TokenCppKind_PPInclude},
  {5, TokenCppKind_PPIf},
  {0, 0},
  {5, TokenCppKind_PPImport},
  {5, TokenCppKind_PPLine},
  {0, 0},
  {0, 0},
  {5, TokenCppKind_PPIfDef},
  {0, 0},
  {5, TokenCppKind_PPPragma},
  {5, TokenCppKind_PPVersion},
  {5, TokenCppKind_PPEndIf},
  {0, 0},
  {5, TokenCppKind_PPElse},
  {5, TokenCppKind_PPError},
  {0, 0},
  {5, TokenCppKind_PPElIf},
  {0, 0},
  {0, 0},
};
i32 cpp_pp_directives_slot_count = 25;
u64 cpp_pp_directives_seed = 0x05b1933e5891d0c2;
u64 cpp_pp_keys_hash_array[2] = {
  0x3ce314bd92b0f81d,0x0000000000000000,
};
u8 cpp_pp_keys_key_array_0[] = {0x64,0x65,0x66,0x69,0x6e,0x65,0x64,};
String_Const_u8 cpp_pp_keys_key_array[2] = {
  {cpp_pp_keys_key_array_0, 7},
  {0, 0},
};
Lexeme_Table_Value cpp_pp_keys_value_array[2] = {
  {4, TokenCppKind_PPDefined},
  {0, 0},
};
i32 cpp_pp_keys_slot_count = 2;
u64 cpp_pp_keys_seed = 0xa0fc762b0838ca62;
struct Lex_State_Cpp{
  u32 flags_ZF0;
  u32 flags_KF0;
  u16 flags_KB0;
  u8 *base;
  u8 *delim_first;
  u8 *delim_one_past_last;
  u8 *emit_ptr;
  u8 *ptr;
  u8 *opl_ptr;
};
internal void
lex_full_input_cpp_init(Lex_State_Cpp *state_ptr, String_Const_u8 input){
  state_ptr->flags_ZF0 = 0;
  state_ptr->flags_KF0 = 0;
  state_ptr->flags_KB0 = 0;
  state_ptr->base = input.str;
  state_ptr->delim_first = input.str;
  state_ptr->delim_one_past_last = input.str;
  state_ptr->emit_ptr = input.str;
  state_ptr->ptr = input.str;
  state_ptr->opl_ptr = input.str + input.size;
}
internal b32
lex_full_input_cpp_breaks(Arena *arena, Token_List *list, Lex_State_Cpp *state_ptr, u64 max){
  b32 result = false;
  u64 emit_counter = 0;
  Lex_State_Cpp state;
  block_copy_struct(&state, state_ptr);
  {
    state_label_1: // root
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
      case 0x07:case 0x08:case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:
      case 0x13:case 0x14:case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:
      case 0x1a:case 0x1b:case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x40:
      case 0x60:case 0x7f:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x09:case 0x0b:case 0x0c:case 0x0d:case 0x20:
      {
        if ((HasFlag(state.flags_KF0, 0x2))){
          state.ptr += 1;
          goto state_label_4; // error_body
        }
        state.ptr += 1;
        goto state_label_3; // whitespace
      }break;
      case 0x0a:
      {
        state.ptr += 1;
        state.flags_KB0 &= ~(0x1);
        state.flags_KF0 &= ~(0x1);
        state.flags_KF0 &= ~(0x2);
        goto state_label_3; // whitespace
      }break;
      case 0x21:
      {
        state.ptr += 1;
        goto state_label_61; // op stage
      }break;
      case 0x22:
      {
        if ((HasFlag(state.flags_KF0, 0x1))){
          state.ptr += 1;
          goto state_label_26; // include_quotes
        }
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x23:
      {
        if ((!HasFlag(state.flags_KB0, 0x1))){
          state.ptr += 1;
          goto state_label_23; // pp_directive_whitespace
        }
        state.ptr += 1;
        goto state_label_68; // op stage
      }break;
      default:
      {
        state.ptr += 1;
        goto state_label_2; // identifier
      }break;
      case 0x25:
      {
        state.ptr += 1;
        goto state_label_65; // op stage
      }break;
      case 0x26:
      {
        state.ptr += 1;
        goto state_label_62; // op stage
      }break;
      case 0x27:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x40;
        goto state_label_32; // string
      }break;
      case 0x28:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_ParenOp;
            token.kind = 13;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x29:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_ParenCl;
            token.kind = 14;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        goto state_label_64; // op stage
      }break;
      case 0x2b:
      {
        state.ptr += 1;
        goto state_label_54; // op stage
      }break;
      case 0x2c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Comma;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2d:
      {
        state.ptr += 1;
        goto state_label_55; // op stage
      }break;
      case 0x2e:
      {
        state.ptr += 1;
        goto state_label_6; // operator_or_fnumber_dot
      }break;
      case 0x2f:
      {
        state.ptr += 1;
        goto state_label_7; // operator_or_comment_slash
      }break;
      case 0x30:
      {
        state.ptr += 1;
        goto state_label_9; // znumber
      }break;
      case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:
      case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_8; // number
      }break;
      case 0x3a:
      {
        state.ptr += 1;
        goto state_label_53; // op stage
      }break;
      case 0x3b:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Semicolon;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3c:
      {
        if ((!HasFlag(state.flags_KF0, 0x1))){
          state.ptr += 1;
          goto state_label_57; // op stage
        }
        state.ptr += 1;
        goto state_label_25; // include_pointy
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        goto state_label_60; // op stage
      }break;
      case 0x3e:
      {
        state.ptr += 1;
        goto state_label_58; // op stage
      }break;
      case 0x3f:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Ternary;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x4;
        goto state_label_27; // pre_L
      }break;
      case 0x52:
      {
        state.ptr += 1;
        goto state_label_31; // pre_R
      }break;
      case 0x55:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x20;
        goto state_label_29; // pre_U
      }break;
      case 0x5b:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BrackOp;
            token.kind = 13;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x5c:
      {
        state.ptr += 1;
        goto state_label_5; // backslash
      }break;
      case 0x5d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BrackCl;
            token.kind = 14;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x5e:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Xor;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x75:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x10;
        goto state_label_28; // pre_u
      }break;
      case 0x7b:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BraceOp;
            token.kind = 11;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x7c:
      {
        state.ptr += 1;
        goto state_label_63; // op stage
      }break;
      case 0x7d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BraceCl;
            token.kind = 12;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x7e:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Tilde;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_2: // identifier
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_KB0, 0x1)){
              Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_pp_keys_hash_array, cpp_pp_keys_key_array, cpp_pp_keys_value_array, cpp_pp_keys_slot_count, cpp_pp_keys_seed, state.emit_ptr, token.size);
              if (lookup.found_match){
                token.kind = lookup.base_kind;
                token.sub_kind = lookup.sub_kind;
                break;
              }
            }
            Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_main_keys_hash_array, cpp_main_keys_key_array, cpp_main_keys_value_array, cpp_main_keys_slot_count, cpp_main_keys_seed, state.emit_ptr, token.size);
            if (lookup.found_match){
              token.kind = lookup.base_kind;
              token.sub_kind = lookup.sub_kind;
              break;
            }
            token.sub_kind = TokenCppKind_Identifier;
            token.kind = 6;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      case 0x00:case 0x01:case 0x02:case 0x03:case 0x04:case 0x05:case 0x06:
      case 0x07:case 0x08:case 0x09:case 0x0a:case 0x0b:case 0x0c:case 0x0d:
      case 0x0e:case 0x0f:case 0x10:case 0x11:case 0x12:case 0x13:case 0x14:
      case 0x15:case 0x16:case 0x17:case 0x18:case 0x19:case 0x1a:case 0x1b:
      case 0x1c:case 0x1d:case 0x1e:case 0x1f:case 0x20:case 0x21:case 0x22:
      case 0x23:case 0x25:case 0x26:case 0x27:case 0x28:case 0x29:case 0x2a:
      case 0x2b:case 0x2c:case 0x2d:case 0x2e:case 0x2f:case 0x3a:case 0x3b:
      case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x5b:case 0x5c:
      case 0x5d:case 0x5e:case 0x60:case 0x7b:case 0x7c:case 0x7d:case 0x7e:
      case 0x7f:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_KB0, 0x1)){
              Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_pp_keys_hash_array, cpp_pp_keys_key_array, cpp_pp_keys_value_array, cpp_pp_keys_slot_count, cpp_pp_keys_seed, state.emit_ptr, token.size);
              if (lookup.found_match){
                token.kind = lookup.base_kind;
                token.sub_kind = lookup.sub_kind;
                break;
              }
            }
            Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_main_keys_hash_array, cpp_main_keys_key_array, cpp_main_keys_value_array, cpp_main_keys_slot_count, cpp_main_keys_seed, state.emit_ptr, token.size);
            if (lookup.found_match){
              token.kind = lookup.base_kind;
              token.sub_kind = lookup.sub_kind;
              break;
            }
            token.sub_kind = TokenCppKind_Identifier;
            token.kind = 6;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      default:
      {
        state.ptr += 1;
        goto state_label_2; // identifier
      }break;
    }
  }
  {
    state_label_3: // whitespace
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Whitespace;
            token.kind = 1;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Whitespace;
            token.kind = 1;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x09:case 0x0b:case 0x0c:case 0x0d:case 0x20:
      {
        state.ptr += 1;
        goto state_label_3; // whitespace
      }break;
      case 0x0a:
      {
        state.ptr += 1;
        state.flags_KB0 &= ~(0x1);
        state.flags_KF0 &= ~(0x1);
        state.flags_KF0 &= ~(0x2);
        goto state_label_3; // whitespace
      }break;
    }
  }
  {
    state_label_4: // error_body
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPErrorMessage;
            token.kind = 10;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_4; // error_body
      }break;
      case 0x0a:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPErrorMessage;
            token.kind = 10;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_5: // backslash
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Backslash;
            token.kind = 1;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Backslash;
            token.kind = 1;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x0a:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Backslash;
            token.kind = 1;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x0d:
      {
        state.ptr += 1;
        goto state_label_5; // backslash
      }break;
    }
  }
  {
    state_label_6: // operator_or_fnumber_dot
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Dot;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Dot;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_DotStar;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2e:
      {
        state.ptr += 1;
        goto state_label_69; // op stage
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_10; // fnumber_decimal
      }break;
    }
  }
  {
    state_label_7: // operator_or_comment_slash
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Div;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Div;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        goto state_label_49; // comment_block
      }break;
      case 0x2f:
      {
        state.ptr += 1;
        goto state_label_51; // comment_line
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_DivEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_8: // number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralInteger;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralInteger;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_8; // number
      }break;
      case 0x2e:
      {
        state.ptr += 1;
        goto state_label_10; // fnumber_decimal
      }break;
      case 0x45:case 0x65:
      {
        state.ptr += 1;
        goto state_label_11; // fnumber_exponent
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_18; // L_number
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        goto state_label_17; // U_number
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_20; // l_number
      }break;
    }
  }
  {
    state_label_9: // znumber
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralInteger;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralInteger;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x2;
        goto state_label_16; // number_oct
      }break;
      case 0x2e:
      {
        state.ptr += 1;
        goto state_label_10; // fnumber_decimal
      }break;
      case 0x42:case 0x58:case 0x62:case 0x78:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x1;
        goto state_label_14; // number_hex_first
      }break;
      case 0x45:case 0x65:
      {
        state.ptr += 1;
        goto state_label_11; // fnumber_exponent
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_18; // L_number
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        goto state_label_17; // U_number
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_20; // l_number
      }break;
    }
  }
  {
    state_label_10: // fnumber_decimal
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_10; // fnumber_decimal
      }break;
      case 0x45:case 0x65:
      {
        state.ptr += 1;
        goto state_label_11; // fnumber_exponent
      }break;
      case 0x46:case 0x66:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat32;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:case 0x6c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_11: // fnumber_exponent
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2b:case 0x2d:
      {
        state.ptr += 1;
        goto state_label_12; // fnumber_exponent_sign
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_13; // fnumber_exponent_digits
      }break;
      case 0x46:case 0x66:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat32;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:case 0x6c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_12: // fnumber_exponent_sign
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_13; // fnumber_exponent_digits
      }break;
      case 0x46:case 0x66:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat32;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:case 0x6c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_13: // fnumber_exponent_digits
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:
      {
        state.ptr += 1;
        goto state_label_13; // fnumber_exponent_digits
      }break;
      case 0x46:case 0x66:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat32;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:case 0x6c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralFloat64;
            token.kind = 9;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_14: // number_hex_first
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:
      case 0x44:case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:
      case 0x65:case 0x66:
      {
        state.ptr += 1;
        goto state_label_15; // number_hex
      }break;
    }
  }
  {
    state_label_15: // number_hex
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralIntegerHex;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralIntegerHex;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:
      case 0x44:case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:
      case 0x65:case 0x66:
      {
        state.ptr += 1;
        goto state_label_15; // number_hex
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_18; // L_number
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        goto state_label_17; // U_number
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_20; // l_number
      }break;
    }
  }
  {
    state_label_16: // number_oct
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralIntegerOct;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LiteralIntegerOct;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x27:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x2;
        goto state_label_16; // number_oct
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_18; // L_number
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        goto state_label_17; // U_number
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_20; // l_number
      }break;
    }
  }
  {
    state_label_17: // U_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexU;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctU;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerU;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexU;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctU;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerU;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_19; // UL_number
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_21; // Ul_number
      }break;
    }
  }
  {
    state_label_18: // L_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        goto state_label_22; // LL_number
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_19: // UL_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x4c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexULL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctULL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerULL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_20: // l_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        goto state_label_22; // LL_number
      }break;
    }
  }
  {
    state_label_21: // Ul_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexUL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctUL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerUL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x6c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexULL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctULL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerULL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_22: // LL_number
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexLL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctLL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerLL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexLL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctLL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerLL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x55:case 0x75:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x1)){
              token.sub_kind = TokenCppKind_LiteralIntegerHexULL;
              token.kind = 8;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x2)){
              token.sub_kind = TokenCppKind_LiteralIntegerOctULL;
              token.kind = 8;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralIntegerULL;
            token.kind = 8;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_23: // pp_directive_whitespace
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x09:case 0x0b:case 0x0c:case 0x20:
      {
        state.ptr += 1;
        goto state_label_23; // pp_directive_whitespace
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
      case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
      case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
      case 0x5a:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:
      case 0x6d:case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:
      case 0x74:case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:
      {
        state.delim_first = state.ptr;
        state.flags_KB0 |= 0x1;
        state.ptr += 1;
        goto state_label_24; // pp_directive
      }break;
    }
  }
  {
    state_label_24: // pp_directive
    if (state.ptr == state.opl_ptr){
      if ((true)){
        state.delim_one_past_last = state.ptr;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_pp_directives_hash_array, cpp_pp_directives_key_array, cpp_pp_directives_value_array, cpp_pp_directives_slot_count, cpp_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
            if (lookup.found_match){
              token.kind = lookup.base_kind;
              token.sub_kind = lookup.sub_kind;
              break;
            }
            token.sub_kind = TokenCppKind_PPUnknown;
            token.kind = 2;
          }while(0);
          switch (token.sub_kind){
            case TokenCppKind_PPInclude:
            {
              state.flags_KF0 |= 0x1;
            }break;
            case TokenCppKind_PPError:
            {
              state.flags_KF0 |= 0x2;
            }break;
          }
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        state.delim_one_past_last = state.ptr;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            Lexeme_Table_Lookup lookup = lexeme_table_lookup(cpp_pp_directives_hash_array, cpp_pp_directives_key_array, cpp_pp_directives_value_array, cpp_pp_directives_slot_count, cpp_pp_directives_seed, state.delim_first, (state.delim_one_past_last - state.delim_first));
            if (lookup.found_match){
              token.kind = lookup.base_kind;
              token.sub_kind = lookup.sub_kind;
              break;
            }
            token.sub_kind = TokenCppKind_PPUnknown;
            token.kind = 2;
          }while(0);
          switch (token.sub_kind){
            case TokenCppKind_PPInclude:
            {
              state.flags_KF0 |= 0x1;
            }break;
            case TokenCppKind_PPError:
            {
              state.flags_KF0 |= 0x2;
            }break;
          }
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
      case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
      case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
      case 0x5a:case 0x5f:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:case 0x67:case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:
      case 0x6d:case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:
      case 0x74:case 0x75:case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:
      {
        state.ptr += 1;
        goto state_label_24; // pp_directive
      }break;
    }
  }
  {
    state_label_25: // include_pointy
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x20:case 0x21:case 0x22:case 0x23:case 0x24:case 0x25:case 0x26:
      case 0x27:case 0x28:case 0x29:case 0x2a:case 0x2b:case 0x2c:case 0x2d:
      case 0x2e:case 0x2f:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:
      case 0x35:case 0x36:case 0x37:case 0x38:case 0x39:case 0x3a:case 0x3b:
      case 0x3d:case 0x3f:case 0x40:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:
      case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:case 0x52:
      case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:case 0x59:
      case 0x5a:case 0x5b:case 0x5c:case 0x5d:case 0x5e:case 0x5f:case 0x61:
      case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:case 0x67:case 0x68:
      case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:case 0x6e:case 0x6f:
      case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:case 0x75:case 0x76:
      case 0x77:case 0x78:case 0x79:case 0x7a:case 0x7b:case 0x7c:case 0x7d:
      {
        state.ptr += 1;
        goto state_label_25; // include_pointy
      }break;
      case 0x3e:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPIncludeFile;
            token.kind = 10;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_26: // include_quotes
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x20:case 0x21:case 0x23:case 0x24:case 0x25:case 0x26:case 0x27:
      case 0x28:case 0x29:case 0x2a:case 0x2b:case 0x2c:case 0x2d:case 0x2e:
      case 0x2f:case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:
      case 0x36:case 0x37:case 0x38:case 0x39:case 0x3a:case 0x3b:case 0x3c:
      case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x41:case 0x42:case 0x43:
      case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:
      case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:case 0x50:case 0x51:
      case 0x52:case 0x53:case 0x54:case 0x55:case 0x56:case 0x57:case 0x58:
      case 0x59:case 0x5a:case 0x5b:case 0x5c:case 0x5d:case 0x5e:case 0x5f:
      case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:case 0x66:case 0x67:
      case 0x68:case 0x69:case 0x6a:case 0x6b:case 0x6c:case 0x6d:case 0x6e:
      case 0x6f:case 0x70:case 0x71:case 0x72:case 0x73:case 0x74:case 0x75:
      case 0x76:case 0x77:case 0x78:case 0x79:case 0x7a:case 0x7b:case 0x7c:
      case 0x7d:
      {
        state.ptr += 1;
        goto state_label_26; // include_quotes
      }break;
      case 0x22:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPIncludeFile;
            token.kind = 10;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_27: // pre_L
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_2; // identifier
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_2; // identifier
      }break;
      case 0x22:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x52:
      {
        state.ptr += 1;
        goto state_label_31; // pre_R
      }break;
    }
  }
  {
    state_label_28: // pre_u
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_2; // identifier
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_2; // identifier
      }break;
      case 0x22:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x38:
      {
        state.ptr += 1;
        state.flags_ZF0 |= 0x8;
        goto state_label_30; // pre_u8
      }break;
      case 0x52:
      {
        state.ptr += 1;
        goto state_label_31; // pre_R
      }break;
    }
  }
  {
    state_label_29: // pre_U
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_2; // identifier
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_2; // identifier
      }break;
      case 0x22:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x52:
      {
        state.ptr += 1;
        goto state_label_31; // pre_R
      }break;
    }
  }
  {
    state_label_30: // pre_u8
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_2; // identifier
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_2; // identifier
      }break;
      case 0x22:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x52:
      {
        state.ptr += 1;
        goto state_label_31; // pre_R
      }break;
    }
  }
  {
    state_label_31: // pre_R
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_2; // identifier
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_2; // identifier
      }break;
      case 0x22:
      {
        state.ptr += 1;
        state.delim_first = state.ptr;
        goto state_label_45; // raw_string_get_delim
      }break;
    }
  }
  {
    state_label_32: // string
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x0a:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x22:
      {
        if ((!HasFlag(state.flags_ZF0, 0x40))){
          state.ptr += 1;
          {
            Token token = {};
            token.pos = (i64)(state.emit_ptr - state.base);
            token.size = (i64)(state.ptr - state.emit_ptr);
            token.flags = state.flags_KB0;
            do{
              if (HasFlag(state.flags_ZF0, 0x4)){
                token.sub_kind = TokenCppKind_LiteralStringWide;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x8)){
                token.sub_kind = TokenCppKind_LiteralStringUTF8;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x10)){
                token.sub_kind = TokenCppKind_LiteralStringUTF16;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x20)){
                token.sub_kind = TokenCppKind_LiteralStringUTF32;
                token.kind = 10;
                break;
              }
              token.sub_kind = TokenCppKind_LiteralString;
              token.kind = 10;
            }while(0);
            token_list_push(arena, list, &token);
            emit_counter += 1;
            state.emit_ptr = state.ptr;
            if (emit_counter == max){
              goto end;
            }
          }
          state.flags_ZF0 = 0;
          goto state_label_1; // root
        }
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x27:
      {
        if ((HasFlag(state.flags_ZF0, 0x40))){
          state.ptr += 1;
          {
            Token token = {};
            token.pos = (i64)(state.emit_ptr - state.base);
            token.size = (i64)(state.ptr - state.emit_ptr);
            token.flags = state.flags_KB0;
            do{
              if (HasFlag(state.flags_ZF0, 0x4)){
                token.sub_kind = TokenCppKind_LiteralCharacterWide;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x8)){
                token.sub_kind = TokenCppKind_LiteralCharacterUTF8;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x10)){
                token.sub_kind = TokenCppKind_LiteralCharacterUTF16;
                token.kind = 10;
                break;
              }
              if (HasFlag(state.flags_ZF0, 0x20)){
                token.sub_kind = TokenCppKind_LiteralCharacterUTF32;
                token.kind = 10;
                break;
              }
              token.sub_kind = TokenCppKind_LiteralCharacter;
              token.kind = 10;
            }while(0);
            token_list_push(arena, list, &token);
            emit_counter += 1;
            state.emit_ptr = state.ptr;
            if (emit_counter == max){
              goto end;
            }
          }
          state.flags_ZF0 = 0;
          goto state_label_1; // root
        }
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x5c:
      {
        state.ptr += 1;
        goto state_label_33; // string_esc
      }break;
    }
  }
  {
    state_label_33: // string_esc
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:
      {
        state.ptr += 1;
        goto state_label_34; // string_esc_oct2
      }break;
      case 0x55:
      {
        state.ptr += 1;
        goto state_label_37; // string_esc_universal_8
      }break;
      case 0x75:
      {
        state.ptr += 1;
        goto state_label_41; // string_esc_universal_4
      }break;
      case 0x78:
      {
        state.ptr += 1;
        goto state_label_36; // string_esc_hex
      }break;
    }
  }
  {
    state_label_34: // string_esc_oct2
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:
      {
        state.ptr += 1;
        goto state_label_35; // string_esc_oct1
      }break;
    }
  }
  {
    state_label_35: // string_esc_oct1
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
    }
  }
  {
    state_label_36: // string_esc_hex
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_36; // string_esc_hex
      }break;
    }
  }
  {
    state_label_37: // string_esc_universal_8
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_38; // string_esc_universal_7
      }break;
    }
  }
  {
    state_label_38: // string_esc_universal_7
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_39; // string_esc_universal_6
      }break;
    }
  }
  {
    state_label_39: // string_esc_universal_6
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_40; // string_esc_universal_5
      }break;
    }
  }
  {
    state_label_40: // string_esc_universal_5
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_41; // string_esc_universal_4
      }break;
    }
  }
  {
    state_label_41: // string_esc_universal_4
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_42; // string_esc_universal_3
      }break;
    }
  }
  {
    state_label_42: // string_esc_universal_3
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_43; // string_esc_universal_2
      }break;
    }
  }
  {
    state_label_43: // string_esc_universal_2
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_44; // string_esc_universal_1
      }break;
    }
  }
  {
    state_label_44: // string_esc_universal_1
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_32; // string
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_32; // string
      }break;
      case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:
      case 0x37:case 0x38:case 0x39:case 0x41:case 0x42:case 0x43:case 0x44:
      case 0x45:case 0x46:case 0x61:case 0x62:case 0x63:case 0x64:case 0x65:
      case 0x66:
      {
        state.ptr += 1;
        goto state_label_32; // string
      }break;
    }
  }
  {
    state_label_45: // raw_string_get_delim
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_45; // raw_string_get_delim
      }break;
      case 0x20:case 0x29:case 0x5c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x28:
      {
        state.delim_one_past_last = state.ptr;
        state.ptr += 1;
        goto state_label_46; // raw_string_find_close
      }break;
    }
  }
  {
    state_label_46: // raw_string_find_close
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_46; // raw_string_find_close
      }break;
      case 0x29:
      {
        state.ptr += 1;
        goto state_label_47; // raw_string_try_delim
      }break;
    }
  }
  {
    state_label_47: // raw_string_try_delim
    u64 delim_length = state.delim_one_past_last - state.delim_first;
    u64 parse_length = 0;
    for (;;){
      if (parse_length == delim_length){
        goto state_label_48; // raw_string_try_quote
      }
      if (state.ptr == state.opl_ptr){
        goto state_label_48; // raw_string_try_quote
      }
      if (*state.ptr == state.delim_first[parse_length]){
        state.ptr += 1;
        parse_length += 1;
      }
      else{
        goto state_label_46; // raw_string_find_close
      }
    }
  }
  {
    state_label_48: // raw_string_try_quote
    if (state.ptr == state.opl_ptr){
      if ((true)){
        goto state_label_46; // raw_string_find_close
      }
    }
    switch (*state.ptr){
      default:
      {
        goto state_label_46; // raw_string_find_close
      }break;
      case 0x22:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            if (HasFlag(state.flags_ZF0, 0x4)){
              token.sub_kind = TokenCppKind_LiteralStringWideRaw;
              token.kind = 10;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x8)){
              token.sub_kind = TokenCppKind_LiteralStringUTF8Raw;
              token.kind = 10;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x10)){
              token.sub_kind = TokenCppKind_LiteralStringUTF16Raw;
              token.kind = 10;
              break;
            }
            if (HasFlag(state.flags_ZF0, 0x20)){
              token.sub_kind = TokenCppKind_LiteralStringUTF32Raw;
              token.kind = 10;
              break;
            }
            token.sub_kind = TokenCppKind_LiteralStringRaw;
            token.kind = 10;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_49: // comment_block
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BlockComment;
            token.kind = 3;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_49; // comment_block
      }break;
      case 0x0a:
      {
        state.ptr += 1;
        state.flags_KB0 &= ~(0x1);
        state.flags_KF0 &= ~(0x1);
        goto state_label_49; // comment_block
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        goto state_label_50; // comment_block_try_close
      }break;
    }
  }
  {
    state_label_50: // comment_block_try_close
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BlockComment;
            token.kind = 3;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EOF;
            token.kind = 0;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_49; // comment_block
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        goto state_label_50; // comment_block_try_close
      }break;
      case 0x2f:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_BlockComment;
            token.kind = 3;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_51: // comment_line
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LineComment;
            token.kind = 3;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_51; // comment_line
      }break;
      case 0x0a:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LineComment;
            token.kind = 3;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x5c:
      {
        state.ptr += 1;
        goto state_label_52; // comment_line_backslashing
      }break;
    }
  }
  {
    state_label_52: // comment_line_backslashing
    if (state.ptr == state.opl_ptr){
      if ((true)){
        result = true;
        goto end;
      }
    }
    switch (*state.ptr){
      default:
      {
        state.ptr += 1;
        goto state_label_51; // comment_line
      }break;
      case 0x0d:
      {
        state.ptr += 1;
        goto state_label_52; // comment_line_backslashing
      }break;
    }
  }
  {
    state_label_53: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Colon;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Colon;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3a:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_ColonColon;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_54: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Plus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Plus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2b:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PlusPlus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PlusEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_55: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Minus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Minus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_MinusMinus;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_MinusEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3e:
      {
        state.ptr += 1;
        goto state_label_56; // op stage
      }break;
    }
  }
  {
    state_label_56: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Arrow;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Arrow;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2a:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_ArrowStar;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_57: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Less;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Less;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3c:
      {
        state.ptr += 1;
        goto state_label_66; // op stage
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        goto state_label_59; // op stage
      }break;
    }
  }
  {
    state_label_58: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Grtr;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Grtr;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_GrtrEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3e:
      {
        state.ptr += 1;
        goto state_label_67; // op stage
      }break;
    }
  }
  {
    state_label_59: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LessEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LessEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3e:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Compare;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_60: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Eq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Eq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_EqEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_61: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Not;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Not;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_NotEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_62: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_And;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_And;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x26:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_AndAnd;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_63: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Or;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Or;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x7c:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_OrOr;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_64: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Star;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Star;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_StarEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_65: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Mod;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_Mod;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_ModEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_66: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LeftLeft;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LeftLeft;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LeftLeftEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_67: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_RightRight;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_RightRight;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x3d:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_RightRightEq;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_68: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPStringify;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPStringify;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x23:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_PPConcat;
            token.kind = 15;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  {
    state_label_69: // op stage
    if (state.ptr == state.opl_ptr){
      if ((true)){
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }
    }
    switch (*state.ptr){
      default:
      {
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_LexError;
            token.kind = 2;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
      case 0x2e:
      {
        state.ptr += 1;
        {
          Token token = {};
          token.pos = (i64)(state.emit_ptr - state.base);
          token.size = (i64)(state.ptr - state.emit_ptr);
          token.flags = state.flags_KB0;
          do{
            token.sub_kind = TokenCppKind_DotDotDot;
            token.kind = 7;
          }while(0);
          token_list_push(arena, list, &token);
          emit_counter += 1;
          state.emit_ptr = state.ptr;
          if (emit_counter == max){
            goto end;
          }
        }
        state.flags_ZF0 = 0;
        goto state_label_1; // root
      }break;
    }
  }
  end:;
  block_copy_struct(state_ptr, &state);
  return(result);
}
internal Token_List
lex_full_input_cpp(Arena *arena, String_Const_u8 input){
  Lex_State_Cpp state = {};
  lex_full_input_cpp_init(&state, input);
  Token_List list = {};
  lex_full_input_cpp_breaks(arena, &list, &state, max_u64);
  return(list);
}
