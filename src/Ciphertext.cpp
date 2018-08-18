/*
* Copyright (c) by CryptoLab inc.
* This program is licensed under a
* Creative Commons Attribution-NonCommercial 3.0 Unported License.
* You should have received a copy of the license along with this
* work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
*/

#include <fstream>
#include "Ciphertext.h"

Ciphertext::Ciphertext() : ax(nullptr), bx(nullptr), N(0), slots(0), l(0) {}

Ciphertext::Ciphertext(uint64_t* ax, uint64_t* bx, long N, long slots, long l) : ax(ax), bx(bx), N(N), slots(slots), l(l){}

Ciphertext::Ciphertext(const Ciphertext& cipher) : N(cipher.N), slots(cipher.slots), l(cipher.l) {
	ax = new uint64_t[N * l];
	bx = new uint64_t[N * l];
	for (long i = 0; i < N * l; ++i) {
		ax[i] = cipher.ax[i];
		bx[i] = cipher.bx[i];
	}
}

Ciphertext& Ciphertext::operator=(const Ciphertext& o) {
	if(this == &o) return *this; // handling of self assignment, thanks for your advice, arul.
	delete[] ax;
	delete[] bx;
	N = o.N;
	l = o.l;
	slots = o.slots;
	ax = new uint64_t[N * l];
	bx = new uint64_t[N * l];
	for (long i = 0; i < N * l; ++i) {
		ax[i] = o.ax[i];
		bx[i] = o.bx[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Ciphertext& cipher)
{
	os << "RNS-HEAAN-Ciphertext" << std::endl;
	os << cipher.N << ' ' << cipher.l << ' ' << cipher.slots << std::endl;
	long count = cipher.N * cipher.l;
	for (long i = 0; i < count; ++i)
		os << cipher.ax[i] << ' ' << cipher.bx[i] << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Ciphertext& cipher)
{
	std::string magic;
	is >> magic;
	if (magic == "RNS-HEAAN-Ciphertext") {
		is >> cipher.N >> cipher.l >> cipher.slots;
		long count = cipher.N * cipher.l;
		delete[] cipher.ax;
		delete[] cipher.bx;
		cipher.ax = new uint64_t[count];
		cipher.bx = new uint64_t[count];
		for (long i = 0; i < count; ++i)
			is >> cipher.ax[i] >> cipher.bx[i];
	}
	return is;
}

void write_ciphertext(const Ciphertext& cipher, const std::string& path)
{
    std::ofstream ofs(path);
    if (ofs.is_open())
        ofs << cipher;
}

void read_ciphertext(Ciphertext& cipher, const std::string& path)
{
    std::ifstream ifs(path);
    if (ifs.is_open())
        ifs >> cipher;
}
