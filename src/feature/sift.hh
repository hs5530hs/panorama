//File: sift.hh
//Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once
#include "feature.hh"
#include "dog.hh"


namespace feature {

// sift algorithm implementation
class SIFT {
	public:
		SIFT(const ScaleSpace& ss,
				const std::vector<SSPoint>& keypoints);
		SIFT(const SIFT&) = delete;

		std::vector<Descriptor> get_descriptor() const;

	protected:
		const ScaleSpace& ss;
		const std::vector<SSPoint>& points;

		Descriptor calc_descriptor(const SSPoint&) const;
};

}
