#!/bin/bash

echo "开始扫描未引用的图片"
echo ""
count=0

if [ ! -d "img" ]; then
	echo "找不到img文件夹"
	exit 1
fi

mkdir -p unusedImgs

for image in img/*; do
	[ -e "$image" ] || continue

	name=$(basename "$image")
	if ! grep -rq "$name" --include="*.md" .; then
		echo "$image"
		mv "$image" unusedImgs
		count=$((count+1))
	fi
done

if (( count == 0 )); then
	echo "没有发现未引用的图片"
else
	echo "共清理了$count张未引用的图片, 暂存到 unusedImgs 文件夹"
fi