1.Tải Code về ổ D
Trong thư mục Game-Master chọn Game.sln
click chuột phải vào thanh FlappyBird chọn Properties. Trong Properties chọn  Configuration Properties\C/C++\General\Addtional Include Directories copy đường path của thư viện SDL :D:\Game\SDL2_ttf\include;D:\Game\SDL2_mixer\include;D:\Game\SDL2_image\include;D:\Game\SDL2\include;%(AdditionalIncludeDirectories)

2.Mô tả :
- Sử dụng chuột hoặc mũi tên lên để điểu khiển con chim đi qua khe giữa 2 cột
- Khoảng cách giữa các cột là ngẫu nhiên vừa đủ để đi qua
- Nếu chim chạm vào cột hoặc điều khiển chim ra ngoài màn hình sẽ thua cuộc


3.Các chức năng:
- Có nhạc nền, âm thanh hiệu ứng giữa các lần click chuột, âm thanh khi va chạm vào cột
- Lưu lại thành tích tốt nhất
- Có hướng dẫn chơi game sau khi nhấn Button play
- Điểm < 10 sẽ được huy chương đồng
- Điểm <100 sẽ được huy chương bạc
- Điểm >1000 sẽ được huy chương vàng


4.Các kỹ thuật lập trình:
- Có sử dụng lớp để xay dựng các đối tượng kiểu Object, Player, điều khiển trò chơi
- Sử dụng đồ họa SDL2
- Có âm thanh, text, hình ảnh
- Có sử dụng con trỏ và mảng


5. Kết luận :
- Chương trình còn sơ xài , hình ảnh chưa đẹp, chưa có lưu tên, độ khó, thay đổi skin nhân vật
- Chương trình sẽ còn phát triển trong tương lai
  + Độ khó tăng lên : các cột có thể di chuyển
  + Thay đổi skin player
  + Chơi online
  + Có thể lưu tên Player
  + Có các hiệu ứng khi va chạm với cột ( rơi , nổ ,...)
