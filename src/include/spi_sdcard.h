/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _SPI_SDCARD_H_
#define _SPI_SDCARD_H_

struct spi_sdcard {
	int type;
	struct spi_slave slave;
};

int spi_sdcard_init(struct spi_sdcard *card,
		const unsigned int bus,
		const unsigned int cs);

int spi_sdcard_single_read(const struct spi_sdcard *card,
		size_t block_address,
		void *buff);

int spi_sdcard_multiple_read(const struct spi_sdcard *card,
		size_t start_block_address,
		size_t end_block_address,
		void *buff);

int spi_sdcard_single_write(const struct spi_sdcard *card,
		size_t block_address,
		void *buff);

int spi_sdcard_read(const struct spi_sdcard *card,
		void *dest,
		size_t offset,
		size_t count);

int spi_sdcard_multiple_write(const struct spi_sdcard *card,
		size_t start_block_address,
		size_t end_block_address,
		void *buff);

int spi_sdcard_erase(const struct spi_sdcard *card,
		size_t start_block_address,
		size_t end_block_address);

int spi_sdcard_erase_all(const struct spi_sdcard *card);

/* get the sdcard size in bytes */
size_t spi_sdcard_size(const struct spi_sdcard *card);

#endif /* _SPI_SDCARD_H_ */
