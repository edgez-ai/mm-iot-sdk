/*
 * Copyright 2022-2024 Morse Micro
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

/**
 * @ingroup MMWLAN_REGDB
 * @defgroup MMWLAN_REGDB_HEADER Template S1G regulatory database header
 *
 * \@{
 *
 * @section MMWLAN_REGDB_OVERRIDE Overriding Regulatory Database
 * The data in the database is defined in @ref mmregdb.c, and can be overwritten as required.
 */

#pragma once

#include "mmwlan.h"

/**
 * Get a pointer to regulatory_db.
 * Stores channel information for each supported domain.
 * For more info, @ref see mmregdb.c.
 *
 * @return Reference to the regulatory database
 */
const struct mmwlan_regulatory_db *get_regulatory_db(void);

/**
 * Resolve one exact S1G channel from the configured regulatory database.
 *
 * @param country_code   Two-character country code plus terminator.
 * @param centre_freq_hz Requested channel center frequency in Hz.
 * @param bandwidth_mhz  Requested operating bandwidth in MHz.
 *
 * @return Matching immutable channel entry, or NULL when no exact match exists.
 */
const struct mmwlan_s1g_channel *mmregdb_lookup_channel(
    const char country_code[MMWLAN_COUNTRY_CODE_LEN],
    uint32_t centre_freq_hz, uint8_t bandwidth_mhz);

/** \@} */
