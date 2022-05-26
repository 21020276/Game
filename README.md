# ***FLAPPY BIRD***


## ***GIỚI THIỆU***
- NGUYỄN TUẤN ANH - K66CD - UET
- MSV 21020276



## ***1.HƯỚNG DẪN CÀI ĐẶT***
- Tải file zip về máy , giải nén
- Tải thư viện SDL2, SDL2_image, SDL2_mixer, SDL2_ttf
- Thêm đường dẫn tới các thư viện SDL https://www.youtube.com/watch?v=pcTnmgz4CZE (Hướng dẫn với Visual Studio, các IDE khác có thể tham khảo youtube)
- Nếu bạn chỉ chơi mà không tham khảo code thì có thể click vào đường link https://drive.google.com/file/d/1nEgc5-94YcV7rVvZX9RMiAUdcMxZWMbR/view?usp=sharing để tải file và giải nén. Sau khi giải nén chạy file exe.
  


## ***2.MÔ TẢ***
- Sử dụng chuột hoặc mũi tên lên để điểu khiển con chim đi qua khe giữa 2 cột
- Khoảng cách giữa các cột là ngẫu nhiên vừa đủ để đi qua
- Nếu chim chạm vào cột hoặc điều khiển chim ra ngoài màn hình sẽ thua cuộc


3.Các chức năng:
- Có nhạc nền, âm thanh hiệu ứng giữa các lần click chuột, âm thanh khi va chạm vào cột
- Lưu lại thành tích tốt nhất
- Có hướng dẫn chơi game sau khi nhấn Button play
- Điểm < 10 sẽ được huy chương đồng ![](FlappyBird/Image/BronzeMedal.png)

- Điểm <100 sẽ được huy chương bạc ![](FlappyBird/Image/SilverMedal.png)

- Điểm >100 sẽ được huy chương vàng ![](FlappyBird/Image/GoldMedal.png)


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
